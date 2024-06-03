class Solution
{
public:
  // https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/?envType=daily-question&envId=2024-05-30
  int countTriplets(vector<int> &arr)
  {
    int n = arr.size();
    int cnt = 0;
    vector<int> pre(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
      pre[i + 1] = arr[i] ^ pre[i];
    }

    for (int i = 0; i < n; i++)
    {
      for (int k = i + 1; k <= n; k++)
      {
        if (pre[i] == pre[k])
        {
          cnt += k - (i + 1);
        }
      }
    }

    return cnt;
  }
};

class Solution
{
public:
  int countTriplets(vector<int> &arr)
  {
    int n = arr.size();
    int cnt = 0;
    vector<int> pre(n + 1, 0);

    unordered_map<int, int> samePref, sumPref;
    samePref[0] = 1;

    for (int i = 0; i < n; i++)
    {
      pre[i + 1] = arr[i] ^ pre[i];
    }

    for (int k = 1; k <= n; k++)
    {
      int x = pre[k];

      cnt += samePref[x] * k - sumPref[x] - samePref[x] * 1;
      samePref[x]++;
      sumPref[x] += k;
    }

    return cnt;
  }
};

class Solution
{
public:
  int countTriplets(vector<int> &arr)
  {
    int n = arr.size();
    int cnt = 0;
    vector<int> pre(n + 1, 0);

    unordered_map<int, int> samePref, sumPref;
    samePref[0] = 1;

    for (int k = 1; k <= n; k++)
    {
      pre[k] = arr[k - 1] ^ pre[k - 1];
      int x = pre[k];

      cnt += samePref[x] * k - sumPref[x] - samePref[x] * 1;
      samePref[x]++;
      sumPref[x] += k;
    }

    return cnt;
  }
};