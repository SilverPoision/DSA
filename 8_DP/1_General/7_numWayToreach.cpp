class Solution
{
public:
  // https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/
  int mod = 1e9 + 7;
  int f(int curr, int end, int k, vector<vector<int>> &dp)
  {
    if (k == 0)
    {
      return curr == end;
    }

    if (dp[curr + 1000][k] != -1)
    {
      return dp[curr + 1000][k];
    }

    int backward = f(curr - 1, end, k - 1, dp);
    int forward = f(curr + 1, end, k - 1, dp);

    return dp[curr + 1000][k] = (forward + backward) % mod;
  }
  int numberOfWays(int s, int e, int k)
  {
    int diff = (e - s);
    if (diff > k || (k - diff) & 1)
      return 0;
    vector<vector<int>> dp(3000, vector<int>(k + 1, -1));
    return f(s, e, k, dp) % mod;
  }
};