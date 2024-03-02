#include <bits/stdc++.h>

int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
  {
    return grid[i][j];
  }

  if (i < 0 || j < 0)
  {
    return 1e9;
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  int up = grid[i][j] + func(i - 1, j, grid, dp);
  int left = grid[i][j] + func(i, j - 1, grid, dp);

  return dp[i][j] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return func(n - 1, m - 1, grid, dp);
}

// Tabulation
int minSumPath(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 && j == 0)
      {
        dp[i][j] = grid[i][j];
      }
      else
      {
        int up = 1e9, left = 1e9;
        if (i > 0)
          up = grid[i][j] + dp[i - 1][j];
        if (j > 0)
          left = grid[i][j] + dp[i][j - 1];
        dp[i][j] = min(up, left);
      }
    }
  }
  return dp[n - 1][m - 1];
}

// S.O
int minSumPath(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<int> prev(m);

  for (int i = 0; i < n; i++)
  {
    vector<int> curr(m);
    for (int j = 0; j < m; j++)
    {
      if (i == 0 && j == 0)
      {
        curr[j] = grid[i][j];
      }
      else
      {
        int up = 1e9, left = 1e9;
        if (i > 0)
          up = grid[i][j] + prev[j];
        if (j > 0)
          left = grid[i][j] + curr[j - 1];
        curr[j] = min(up, left);
      }
    }
    prev = curr;
  }
  return prev[m - 1];
}