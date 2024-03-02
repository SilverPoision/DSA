#include <bits/stdc++.h>

long func(int ind, int *coins, int n, int value, vector<vector<long>> &dp)
{
  if (ind == 0)
  {
    if (value % coins[ind] == 0)
    {
      return 1;
    }
    return 0;
  }

  if (dp[ind][value] != -1)
  {
    return dp[ind][value];
  }

  long notTake = func(ind - 1, coins, n, value, dp);
  long take = 0;
  if (value >= coins[ind])
    take = func(ind, coins, n, value - coins[ind], dp);

  return dp[ind][value] = notTake + take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
  vector<vector<long>> dp(n, vector<long>(value + 1, -1));
  return func(n - 1, denominations, n, value, dp);
}

// Tab
#include <bits/stdc++.h>

long countWaysToMakeChange(int *coins, int n, int value)
{
  vector<vector<long>> dp(n, vector<long>(value + 1, 0));
  for (int i = 0; i <= value; i++)
  {
    if (i % coins[0] == 0)
    {
      dp[0][i] = 1;
    }
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int j = 0; j <= value; j++)
    {
      long notTake = dp[ind - 1][j];
      long take = 0;
      if (j >= coins[ind])
        take = dp[ind][j - coins[ind]];
      dp[ind][j] = notTake + take;
    }
  }

  return dp[n - 1][value];
}

// S.O
#include <bits/stdc++.h>

long countWaysToMakeChange(int *coins, int n, int value)
{
  vector<long> prev(value + 1, 0), curr(value + 1, 0);
  for (int i = 0; i <= value; i++)
  {
    if (i % coins[0] == 0)
    {
      prev[i] = 1;
    }
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int j = 0; j <= value; j++)
    {
      long notTake = prev[j];
      long take = 0;
      if (j >= coins[ind])
        take = curr[j - coins[ind]];
      curr[j] = notTake + take;
    }
    prev = curr;
  }

  return prev[value];
}

// Ultra s.o
#include <bits/stdc++.h>

long countWaysToMakeChange(int *coins, int n, int value)
{
  vector<long> curr(value + 1, 0);
  for (int i = 0; i <= value; i++)
  {
    if (i % coins[0] == 0)
    {
      curr[i] = 1;
    }
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int j = 0; j <= value; j++)
    {
      long notTake = curr[j];
      long take = 0;
      if (j >= coins[ind])
        take = curr[j - coins[ind]];
      curr[j] = notTake + take;
    }
  }

  return curr[value];
}