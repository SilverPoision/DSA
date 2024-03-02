#include <bits/stdc++.h>
int mod = 1e9 + 7;

int countSubsequence(int i, int j, string t, string s, vector<vector<int>> &dp)
{
  if (j == 0)
    return 1;
  if (i == 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (t[i - 1] == s[j - 1])
    return dp[i][j] = (countSubsequence(i - 1, j - 1, t, s, dp) + countSubsequence(i - 1, j, t, s, dp)) % mod;
  else
    return dp[i][j] = countSubsequence(i - 1, j, t, s, dp) % mod;
}

int subsequenceCounting(string &t, string &s, int m, int n)
{
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return countSubsequence(m, n, t, s, dp);
}

// Tab
#include <bits/stdc++.h>
int subsequenceCounting(string &t, string &s, int m, int n)
{
  int mod = 1e9 + 7;
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= m; i++)
  {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (t[i - 1] == s[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        dp[i][j] %= mod;
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] %= mod;
      }
    }
  }
  return dp[m][n];
}

// S.O
#include <bits/stdc++.h>
int subsequenceCounting(string &t, string &s, int m, int n)
{
  int mod = 1e9 + 7;
  vector<int> prev(n + 1, 0), curr(n + 1, 0);

  prev[0] = curr[0] = 1;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (t[i - 1] == s[j - 1])
      {
        curr[j] = prev[j - 1] + prev[j];
        curr[j] %= mod;
      }
      else
      {
        curr[j] = prev[j];
        curr[j] %= mod;
      }
    }
    prev = curr;
  }
  return prev[n];
}

// Ultra S.O
#include <bits/stdc++.h>
int subsequenceCounting(string &t, string &s, int m, int n)
{
  int mod = 1e9 + 7;
  vector<int> curr(n + 1, 0);

  curr[0] = 1;

  for (int i = 1; i <= m; i++)
  {
    for (int j = n; j > 0; j--)
    {
      if (t[i - 1] == s[j - 1])
      {
        curr[j] = curr[j - 1] + curr[j];
        curr[j] %= mod;
      }
      else
      {
        curr[j] = curr[j];
        curr[j] %= mod;
      }
    }
  }
  return curr[n];
}