class Solution
{
public:
  // https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/
  int solve(int j, int keep, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
  {
    if (j >= m)
    {
      return 0;
    }

    if (dp[j][keep] != -1)
      return dp[j][keep];

    int cost = 0;
    for (int k = 0; k < n; k++)
    {
      if (grid[k][j] != keep)
        cost++;
    }

    int mini = 1e9;
    for (int i = 0; i <= 9; i++)
    {
      if (i == keep)
        continue;
      mini = min(mini, cost + solve(j + 1, i, n, m, grid, dp));
    }

    return dp[j][keep] = mini;
  }
  int minimumOperations(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(10, -1));

    int mini = 1e9;
    for (int i = 0; i <= 9; i++)
    {
      mini = min(mini, solve(0, i, n, m, grid, dp));
    }

    return mini;
  }
};