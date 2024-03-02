int func(int i, int j, vector<vector<int>> &tri, int n, vector<vector<int>> &dp)
{
  if (i == n - 1 && j >= 0 && j < n)
  {
    return tri[i][j];
  }

  if (i > n && j > n)
  {
    return 1e9;
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  int down = tri[i][j] + func(i + 1, j, tri, n, dp);
  int diag = tri[i][j] + func(i + 1, j + 1, tri, n, dp);

  return dp[i][j] = min(down, diag);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return func(0, 0, triangle, n, dp);
}

// Tab
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    dp[n - 1][i] = triangle[n - 1][i];
  }
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = i; j >= 0; j--)
    {
      int down = triangle[i][j] + dp[i + 1][j];
      int diag = triangle[i][j] + dp[i + 1][j + 1];
      dp[i][j] = min(down, diag);
    }
  }
  return dp[0][0];
}

// S.O
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
  vector<int> prev(n, 0), curr(n, 0);
  for (int i = 0; i < n; i++)
  {
    prev[i] = triangle[n - 1][i];
  }
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = i; j >= 0; j--)
    {
      int down = triangle[i][j] + prev[j];
      int diag = triangle[i][j] + prev[j + 1];
      curr[j] = min(down, diag);
    }
    prev = curr;
  }
  return prev[0];
}