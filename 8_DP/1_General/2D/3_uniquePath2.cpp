int mod = (int)(1e9 + 7);
int func(int n, int m, vector<vector<int>> &mat)
{
  if (n == 0 && m == 0)
  {
    return 1;
  }

  if (n < 0 || m < 0 || mat[n][m] == -1)
  {
    return 0;
  }

  int up = func(n - 1, m, mat);
  int right = func(n, m - 1, mat);

  return (up + right) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
  return func(n - 1, m - 1, mat);
}

// Memo
int mod = (int)(1e9 + 7);
int func(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{

  if (n >= 0 && m >= 0 && mat[n][m] == -1)
  {
    return 0;
  }

  if (n == 0 && m == 0)
  {
    return 1;
  }

  if (n < 0 || m < 0)
  {
    return 0;
  }

  if (dp[n][m] != -1)
  {
    return dp[n][m];
  }

  int up = func(n - 1, m, mat, dp);
  int right = func(n, m - 1, mat, dp);

  return dp[n][m] = (up + right) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return func(n - 1, m - 1, mat, dp);
}

// Tabulation
int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
  vector<vector<int>> dp(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == -1)
      {
        dp[i][j] = 0;
      }
      else if (i == 0 && j == 0)
      {
        dp[i][j] = 1;
      }
      else
      {
        int up = 0;
        int right = 0;
        if (i > 0)
          up = dp[i - 1][j];
        if (j > 0)
          right = dp[i][j - 1];
        dp[i][j] = (up + right) % mod;
      }
    }
  }
  return dp[n - 1][m - 1];
}

// S.O
int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
  vector<int> prev(m, 0);
  for (int i = 0; i < n; i++)
  {
    vector<int> curr(m, 0);
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == -1)
      {
        curr[j] = 0;
      }
      else if (i == 0 && j == 0)
      {
        curr[j] = 1;
      }
      else
      {
        int up = 0;
        int right = 0;
        if (i > 0)
          up = prev[j];
        if (j > 0)
          right = curr[j - 1];
        curr[j] = (up + right) % mod;
      }
    }
    prev = curr;
  }
  return prev[m - 1];
}