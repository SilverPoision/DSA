#include <bits/stdc++.h>

int fun(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
  if (j < 0 || j >= matrix[0].size())
  {
    return -1e9;
  }
  if (i == 0)
  {
    return matrix[i][j];
  }

  if (dp[i][j] != -1)
    return dp[i][j];

  int up = matrix[i][j] + fun(i - 1, j, matrix, dp);
  int leftD = matrix[i][j] + fun(i - 1, j - 1, matrix, dp);
  int rightD = matrix[i][j] + fun(i - 1, j + 1, matrix, dp);

  return dp[i][j] = max(up, max(leftD, rightD));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
  int i = matrix.size();
  int j = matrix[0].size();
  vector<vector<int>> dp(i, vector<int>(j, -1));

  int maxi = -1e9;
  for (int k = 0; k < j; k++)
  {
    int ans = fun(i - 1, k, matrix, dp);
    maxi = max(maxi, ans);
  }
  return maxi;
}

// Tab
#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();

  vector<vector<int>> dp(n, vector<int>(m, -1));
  for (int j = 0; j < m; j++)
  {
    dp[0][j] = matrix[0][j];
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int up = -1e9, leftD = -1e9, rightD = -1e9;
      if (i > 0)
        up = matrix[i][j] + dp[i - 1][j];
      if (i > 0 && j > 0)
        leftD = matrix[i][j] + dp[i - 1][j - 1];
      if (i > 0 && j < m - 1)
        rightD = matrix[i][j] + dp[i - 1][j + 1];

      dp[i][j] = max(up, max(leftD, rightD));
    }
  }

  int maxi = -1e9;
  for (int i = 0; i < m; i++)
  {
    maxi = max(dp[n - 1][i], maxi);
  }
  return maxi;
}

// S.O
#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();

  vector<int> prev(m), curr(m);
  for (int j = 0; j < m; j++)
  {
    prev[j] = matrix[0][j];
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int up = -1e9, leftD = -1e9, rightD = -1e9;
      if (i > 0)
        up = matrix[i][j] + prev[j];
      if (i > 0 && j > 0)
        leftD = matrix[i][j] + prev[j - 1];
      if (i > 0 && j < m - 1)
        rightD = matrix[i][j] + prev[j + 1];

      curr[j] = max(up, max(leftD, rightD));
    }
    prev = curr;
  }

  int maxi = -1e9;
  for (int i = 0; i < m; i++)
  {
    maxi = max(prev[i], maxi);
  }
  return maxi;
}