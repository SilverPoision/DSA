class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1
  int dp[100001];
  int solve(int n, int x, int y)
  {
    if (n == 1 || n == x || n == y)
      return 1;

    if (dp[n] != -1)
      return dp[n];

    if (n - 1 >= 0 && solve(n - 1, x, y) == 0)
    {
      return dp[n] = 1;
    }

    if (n - x >= 0 && solve(n - x, x, y) == 0)
    {
      return dp[n] = 1;
    }

    if (n - y >= 0 && solve(n - y, x, y) == 0)
    {
      return dp[n] = 1;
    }

    return dp[n] = 0;
  }
  int findWinner(int n, int x, int y)
  {
    // code here
    memset(dp, -1, sizeof(dp));
    return solve(n, x, y);
  }
};