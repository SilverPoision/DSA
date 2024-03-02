#include <bits/stdc++.h>

bool match(int i, int j, string s, string t, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
  {
    return true;
  }
  if (i == 0 && j > 0)
  {
    return false;
  }
  if (j == 0 && i > 0)
  {
    for (int k = 1; k <= i; k++)
    {
      if (s[k - 1] != '*')
      {
        return false;
      }
    }
    return true;
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
  {
    return dp[i][j] = match(i - 1, j - 1, s, t, dp);
  }
  if (s[i - 1] == '*')
  {
    return dp[i][j] = match(i - 1, j, s, t, dp) || match(i, j - 1, s, t, dp);
  }
  return false;
}

bool wildcardMatching(string pattern, string text)
{
  int n = pattern.size();
  int m = text.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return match(n, m, pattern, text, dp);
}

// Tab
#include <bits/stdc++.h>

bool wildcardMatching(string s, string t)
{
  int n = s.size();
  int m = t.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
  dp[0][0] = true;

  for (int i = 0; i <= n; i++)
  {
    bool m = true;
    for (int k = 1; k <= i; k++)
    {
      if (s[k - 1] != '*')
      {
        dp[i][0] = false;
        m = false;
        continue;
      }
    }
    if (m)
      dp[i][0] = true;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else if (s[i - 1] == '*')
      {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      }
      else
        curr[j] = false;
    }
  }
  return dp[n][m];
}

// S.O
#include <bits/stdc++.h>

bool isAllStars(string &S1, int i)
{
  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++)
  {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

bool wildcardMatching(string &s, string &t)
{
  int n = s.size();
  int m = t.size();
  vector<bool> prev(m + 1, false), curr(m + 1, false);
  prev[0] = true;

  for (int i = 1; i <= n; i++)
  {
    curr[0] = isAllStars(s, i);
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
      {
        curr[j] = prev[j - 1];
      }
      else if (s[i - 1] == '*')
      {
        curr[j] = prev[j] || curr[j - 1];
      }
      else
        curr[j] = false;
    }
    prev = curr;
  }
  return prev[m];
}
