#include <bits/stdc++.h>

int func(int ind, vector<int> weight, vector<int> value, int maxi, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    if (maxi >= weight[ind])
    {
      return value[ind];
    }
    else
    {
      return 0;
    }
  }

  if (dp[ind][maxi] != -1)
  {
    return dp[ind][maxi];
  }

  int notTake = func(ind - 1, weight, value, maxi, dp);
  int take = 0;
  if (maxi >= weight[ind])
    take = value[ind] + func(ind - 1, weight, value, maxi - weight[ind], dp);

  return dp[ind][maxi] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  return func(n - 1, weight, value, maxWeight, dp);
}

// tab
#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
  for (int i = weight[0]; i <= maxWeight; i++)
  {
    dp[0][i] = value[0];
  }

  for (int i = 1; i < n; i++)
  {
    for (int maxi = 0; maxi <= maxWeight; maxi++)
    {
      int notTake = dp[i - 1][maxi];
      int take = 0;
      if (maxi >= weight[i])
        take = value[i] + dp[i - 1][maxi - weight[i]];
      dp[i][maxi] = max(take, notTake);
    }
  }

  return dp[n - 1][maxWeight];
}

// S.O
#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
  for (int i = weight[0]; i <= maxWeight; i++)
  {
    prev[i] = value[0];
  }

  for (int i = 1; i < n; i++)
  {
    for (int maxi = 0; maxi <= maxWeight; maxi++)
    {
      int notTake = prev[maxi];
      int take = 0;
      if (maxi >= weight[i])
        take = value[i] + prev[maxi - weight[i]];
      curr[maxi] = max(take, notTake);
    }
    prev = curr;
  }

  return prev[maxWeight];
}

// Ultra S.O
#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<int> prev(maxWeight + 1, 0);
  for (int i = weight[0]; i <= maxWeight; i++)
  {
    prev[i] = value[0];
  }

  for (int i = 1; i < n; i++)
  {
    for (int maxi = maxWeight; maxi >= 0; maxi--)
    {
      int notTake = prev[maxi];
      int take = 0;
      if (maxi >= weight[i])
        take = value[i] + prev[maxi - weight[i]];
      prev[maxi] = max(take, notTake);
    }
  }

  return prev[maxWeight];
}
