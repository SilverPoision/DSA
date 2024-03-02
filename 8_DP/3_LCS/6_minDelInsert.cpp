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

int canYouMake(string &str, string &ptr)
{
  int total = str.size() + ptr.size();
  int common = lcs(str, ptr);

  return total - 2 * common;
}