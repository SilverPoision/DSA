class Solution
{
public:
  // https://leetcode.com/problems/integer-break/https://leetcode.com/problems/integer-break/
  vector<int> dp;
  int solve(int n)
  {
    if (n == 1)
      return 1;

    if (dp[n] != -1)
      return dp[n];

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
      ans = max(ans, i * max(n - i, solve(n - i)));
    }

    return dp[n] = ans;
  }
  int integerBreak(int n)
  {
    dp = vector<int>(n + 1, -1);
    return solve(n);
  }
};