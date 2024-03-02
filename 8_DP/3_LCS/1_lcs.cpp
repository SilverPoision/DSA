#include <bits/stdc++.h>

int f(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
{
  if (ind1 < 0 || ind2 < 0)
  {
    return 0;
  }

  if (dp[ind1][ind2] != -1)
  {
    return dp[ind1][ind2];
  }

  if (s[ind1] == t[ind2])
  {
    return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, s, t, dp);
  }

  return dp[ind1][ind2] = max(f(ind1 - 1, ind2, s, t, dp), f(ind1, ind2 - 1, s, t, dp));
}

int lcs(string s, string t)
{
  int n = s.length();
  int m = t.length();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return f(n - 1, m - 1, s, t, dp);
}

// Tab
#include <bits/stdc++.h>

int lcs(string s, string t)
{
  int n = s.length();
  int m = t.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = 0;
  }

  for (int i = 0; i <= m; i++)
  {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1]) // shifting of index because of the base case
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

// S.O
#include <bits/stdc++.h>

int lcs(string s, string t)
{
  int n = s.length();
  int m = t.length();
  vector<int> prev(m + 1, 0), curr(m + 1, 0);

  for (int i = 0; i <= m; i++)
  {
    prev[i] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == t[j - 1])
      {
        curr[j] = 1 + prev[j - 1];
      }
      else
      {
        curr[j] = max(prev[j], curr[j - 1]);
      }
    }
    prev = curr;
  }
  return prev[m];
}

// print the string by travelling the dp matrix.
// https://www.youtube.com/watch?v=-zI4mrF2Pb4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY