#pragma GCC optimize("Ofast", "inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")

class Solution
{
public:
  // https://leetcode.com/problems/get-equal-substrings-within-budget/
  int equalSubstring(string s, string t, int maxCost)
  {
    int n = s.size();
    vector<int> diff(n);

    for (int i = 0; i < n; i++)
    {
      int sI = s[i] - 'a';
      int tI = t[i] - 'a';
      diff[i] = abs(sI - tI);
    }

    int maxi = 0;
    int i = 0, j = 0;
    int tempC = maxCost;

    while (j < n)
    {
      while (diff[j] < maxCost && tempC < diff[j])
      {
        tempC += diff[i++];
      }

      if (diff[j] > maxCost)
      {
        j++;
        i = j;
        tempC = maxCost;
        continue;
      }

      tempC -= diff[j];
      maxi = max(maxi, j - i + 1);
      j++;
    }

    return maxi;
  }
};

//
class Solution
{
public:
  int equalSubstring(string s, string t, int k)
  {
    int n = s.length(), i = 0, j;
    for (j = 0; j < n; ++j)
    {
      if ((k -= abs(s[j] - t[j])) < 0)
        k += abs(s[i] - t[i++]);
    }
    return j - i;
  }
};