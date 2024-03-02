int edit(int i, int j, string s, string t, vector<vector<int>> &dp)
{
  if (j < 0)
  {
    return i + 1;
  }
  if (i < 0)
  {
    return j + 1;
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  if (s[i - 1] == t[j - 1])
  {
    return dp[i][j] = edit(i - 1, j - 1, s, t, dp);
  }
  else
  {
    return dp[i][j] = min(1 + edit(i - 1, j - 1, s, t, dp), min(1 + edit(i, j - 1, s, t, dp), 1 + edit(i - 1, j, s, t, dp)));
  }
}

int editDistance(string str1, string str2)
{
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return edit(n, m, str1, str2, dp);
}

// Tab
int editDistance(string s, string t)
{
  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = i;
  }
  for (int j = 0; j <= m; j++)
  {
    dp[0][j] = j;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = min(1 + dp[i - 1][j], min(1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]));
      }
    }
  }
  return dp[n][m];
}

// S.O
int editDistance(string s, string t)
{
  int n = s.size();
  int m = t.size();
  vector<int> prev(m + 1, 0), curr(m + 1, 0);
  for (int i = 0; i <= m; i++)
  {
    prev[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    curr[0] = i;
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        curr[j] = prev[j - 1];
      }
      else
      {
        curr[j] = min(1 + prev[j], min(1 + curr[j - 1], 1 + prev[j - 1]));
      }
    }
    prev = curr;
  }
  return prev[m];
}