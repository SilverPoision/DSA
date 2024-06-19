class Solution
{
public:
  // https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/
  int valueAfterKSeconds(int n, int k)
  {
    int mod = 1e9 + 7;
    vector<long long> pre(n, 1);
    while (k--)
    {
      for (int i = 1; i < n; i++)
      {
        pre[i] = (pre[i] + pre[i - 1]) % mod;
      }
    }

    return pre[n - 1] % mod;
  }
};