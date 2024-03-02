#include <bits/stdc++.h>

bool checkPalidrome(int start, int end, string &str)
{
  while (start < end)
  {
    if (str[start++] != str[end--])
      return false;
  }
  return true;
}

int f(int i, int n, string &str, vector<int> &dp)
{
  if (i == n)
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int part = 1e9;
  for (int ind = i; ind < n; ind++)
  {
    if (checkPalidrome(i, ind, str))
    {
      int ways = 1 + f(ind + 1, n, str, dp);
      part = min(part, ways);
    }
  }

  return dp[i] = part;
}
int palindromePartitioning(string str)
{
  int n = str.size();
  vector<int> dp(n, -1);
  return f(0, n, str, dp) - 1;
}

// Tab
#include <bits/stdc++.h>

bool checkPalidrome(int start, int end, string &str)
{
  while (start < end)
  {
    if (str[start++] != str[end--])
      return false;
  }
  return true;
}

int palindromePartitioning(string str)
{
  int n = str.size();
  vector<int> dp(n + 1, 0);

  for (int i = n - 1; i >= 0; i--)
  {
    int part = 1e9;
    for (int ind = i; ind < n; ind++)
    {
      if (checkPalidrome(i, ind, str))
      {
        int ways = 1 + dp[ind + 1];
        part = min(part, ways);
      }
    }
    dp[i] = part;
  }
  return dp[0] - 1;
}

// Most Optimal Gap Method
class Solution
{
public:
  int minCut(string s)
  {
    // Techdoes
    // https://www.youtube.com/watch?v=UflHuQj6MVA&t=690s  11:00min
    int n = s.size();
    vector<vector<bool>> check(n, vector<bool>(n, false)); // filling the vector to identify that if a range is a palindrome or not.

    for (int gap = 0; gap < n; gap++)
    {
      for (int i = 0, j = gap; j < n; i++, j++)
      {
        if (gap == 0)
        {
          check[i][j] = 1;
        }
        else if (gap == 1)
        {
          check[i][j] = s[i] == s[j];
        }
        else
        {
          check[i][j] = (s[i] == s[j] ? (check[i + 1][j - 1] == 1 ? 1 : 0) : 0);
        }
      }
    }

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
      int part = 1e9;
      for (int ind = i; ind < n; ind++)
      {
        if (check[i][ind])
        {
          int ways = 1 + dp[ind + 1];
          part = min(part, ways);
        }
      }
      dp[i] = part;
    }
    return dp[0] - 1;
  }
};