int f(int i, int j, string &s, vector<vector<int>> &dp)
{
  if (i > j)
    return 0;

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  if (s[i] == s[j])
  {
    return 1 + f(i + 1, j, s, dp) + f(i, j - 1, s, dp);
  }

  return dp[i][j] = (f(i + 1, j, s, dp) + f(i, j - 1, s, dp)) - f(i + 1, j - 1, s, dp);
}

int countPalindromicSubsequences(string &s)
{
  // Write your code here.
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return f(0, s.length() - 1, s, dp);
}

// Tab and optimal
int countPalindromicSubsequences(string &s)
{
  // Write your code here.
  int n = s.size();
  int mod = 1e9 + 7;
  vector<vector<long long int>> dp(n, vector<long long int>(n, 0));

  for (int g = 0; g < n; g++)
  {
    for (int i = 0, j = g; j < n; i++, j++)
    {
      if (g == 0)
      {
        dp[i][j] = 1;
      }
      else if (g == 1)
      {
        dp[i][j] = s[i] == s[j] ? 3 : 2;
      }
      else
      {
        if (s[i] == s[j])
        {
          dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % mod;
        }
        else
        {
          dp[i][j] = (((dp[i + 1][j] + dp[i][j - 1]) - dp[i + 1][j - 1]) + mod) % mod;
        }
      }
    }
  }

  return (dp[0][n - 1] + mod) % mod;
}
