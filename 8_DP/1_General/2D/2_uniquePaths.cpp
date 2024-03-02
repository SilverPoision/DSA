// Memo
#include <bits/stdc++.h>

int func(int i, int j, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
  {
    return 1;
  }

  if (i < 0 || j < 0)
    return 0;

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  int up = func(i - 1, j, dp);
  int left = func(i, j - 1, dp);
  return dp[i][j] = up + left;
}

int uniquePaths(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return func(m - 1, n - 1, dp);
}

// Tabulation
#include <bits/stdc++.h>

int uniquePaths(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == 0 && j == 0)
      {
        dp[i][j] = 1;
      }
      else
      {
        int up = 0, left = 0;
        if (i > 0)
          up = dp[i - 1][j];
        if (j > 0)
          left = dp[i][j - 1];
        dp[i][j] = up + left;
      }
    }
  }
  return dp[m - 1][n - 1];
}

// S.O

#include <bits/stdc++.h>

int uniquePaths(int m, int n)
{
  vector<int> dp(n, 0);
  for (int i = 0; i < m; i++)
  {
    vector<int> temp(n, 0);
    for (int j = 0; j < n; j++)
    {
      if (i == 0 && j == 0)
      {
        dp[i] = 1;
        temp[j] = 1;
      }
      else
      {
        int up = 0, left = 0;
        if (i > 0)
          up = dp[j];
        if (j > 0)
          left = temp[j - 1];
        temp[j] = up + left;
      }
    }
    dp = temp;
  }
  return dp[n - 1];
}

// Combinatrics
#include <bits/stdc++.h>

int uniquePaths(int m, int n)
{
  int N = m + n - 2;
  int r = m - 1;

  int res = 1;

  for (int i = 1; i <= r; i++)
  {
    res = res * (N - r + i) / i;
  }
  return res;
}