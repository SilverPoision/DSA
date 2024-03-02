#include <bits/stdc++.h>

string shortestSupersequence(string a, string b)
{
  int n = a.size();
  int m = b.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string ans = "";

  while (n > 0 && m > 0)
  {
    if (a[n - 1] == b[m - 1])
    {
      ans += a[n - 1];
      n--;
      m--;
    }
    else if (dp[n - 1][m] > dp[n][m - 1])
    {
      ans += a[n - 1];
      n--;
    }
    else
    {
      ans += b[m - 1];
      m--;
    }
  }

  while (n > 0)
  {
    ans += a[n - 1];
    n--;
  }
  while (m > 0)
  {
    ans += b[m - 1];
    m--;
  }

  reverse(ans.begin(), ans.end());
  return ans;
}
