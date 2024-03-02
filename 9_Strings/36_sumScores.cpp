class Solution
{
public:
  // https://leetcode.com/problems/sum-of-scores-of-built-strings/solutions/
  // try to learn about the rolling hash binary search solution and also the kmp one
  vector<int> zAlgo(string &s)
  {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0; // matching window l-r
    for (int i = 1; i < n; i++)
    {
      if (i > r)
      { // that means i is out of the window and we have to match
        // it with the naive way
        l = r = i;
        while (r < n && s[r] == s[r - l])
        {
          r++;
        }
        z[i] = r - l; //(r-l+1) but r is already one more because of the inc
        r--;
      }
      else
      {
        int k = i - l; // to find the corrosponding element from the starting
        if (z[k] < r - i + 1)
        { // to check is the value at z[k] doesnt
          // streaches after r or at r
          z[i] = z[k];
        }
        else
        {
          l = i; // to start the matching from i pointer because that where the window broke
          while (r < n && s[r] == s[r - l])
          {
            r++;
          }

          z[i] = r - l;
          r--;
        }
      }
    }

    return z;
  }
  long long sumScores(string s)
  {
    vector<int> z = zAlgo(s); // pure z algo

    long long ans = 0;

    for (auto it : z)
    {
      ans += it;
    }

    return ans + s.size();
  }
};