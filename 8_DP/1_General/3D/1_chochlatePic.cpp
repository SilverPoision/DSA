#include <bits/stdc++.h>

int func(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp)
{
  if (j1 > m - 1 || j1 < 0 || j2 > m - 1 || j2 < 0)
  {
    return -1e9;
  }

  if (i == n - 1)
  {
    if (j1 == j2)
    {
      return grid[i][j1];
    }
    else
    {
      return grid[i][j1] + grid[i][j2];
    }
  }

  if (dp[i][j1][j2] != -1)
  {
    return dp[i][j1][j2];
  }

  int maxi = -1e9;
  for (int a = -1; a < 2; a++)
  {
    for (int b = -1; b < 2; b++)
    {
      if (j1 + a == j2 + b)
        maxi = max(maxi, grid[i][j1] + func(i + 1, j1 + a, j2 + b, grid, n, m, dp));
      else
        maxi = max(maxi, grid[i][j1] + grid[i][j2] + func(i + 1, j1 + a, j2 + b, grid, n, m, dp));
    }
  }
  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
  return func(0, 0, c - 1, grid, r, c, dp);
}

// Tab
#include <bits/stdc++.h>

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
  for (int j1 = 0; j1 < c; j1++)
  {
    for (int j2 = 0; j2 < c; j2++)
    {
      if (j1 == j2)
        dp[r - 1][j1][j2] = grid[r - 1][j1];
      else
        dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
    }
  }

  for (int i = r - 2; i >= 0; i--)
  {
    for (int j1 = 0; j1 < c; j1++)
    {
      for (int j2 = 0; j2 < c; j2++)
      {
        int maxi = -1e9;
        for (int a = -1; a < 2; a++)
        {
          for (int b = -1; b < 2; b++)
          {
            int val = -1e9;
            if (j1 == j2)
              val = grid[i][j1];
            else
              val = grid[i][j1] + grid[i][j2];
            if ((j1 + a < 0 || j1 + a >= c) || (j2 + b < 0 || j2 + b >= c))
              val += -1e9;
            else
              val += dp[i + 1][j1 + a][j2 + b];
            maxi = max(maxi, val);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }
  return dp[0][0][c - 1];
}

// S.O
#include <bits/stdc++.h>

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
  vector<vector<int>> prev(c, vector<int>(c, -1)), curr(c, vector<int>(c, -1));
  for (int j1 = 0; j1 < c; j1++)
  {
    for (int j2 = 0; j2 < c; j2++)
    {
      if (j1 == j2)
        prev[j1][j2] = grid[r - 1][j1];
      else
        prev[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
    }
  }

  for (int i = r - 2; i >= 0; i--)
  {
    for (int j1 = 0; j1 < c; j1++)
    {
      for (int j2 = 0; j2 < c; j2++)
      {
        int maxi = -1e9;
        for (int a = -1; a < 2; a++)
        {
          for (int b = -1; b < 2; b++)
          {
            int val = -1e9;
            if (j1 == j2)
              val = grid[i][j1];
            else
              val = grid[i][j1] + grid[i][j2];
            if ((j1 + a < 0 || j1 + a >= c) || (j2 + b < 0 || j2 + b >= c))
              val += -1e9;
            else
              val += prev[j1 + a][j2 + b];
            maxi = max(maxi, val);
          }
        }
        curr[j1][j2] = maxi;
      }
    }
    prev = curr;
  }
  return prev[0][c - 1];
}
