#include <bits/stdc++.h>

int func(int ind, vector<int> &profit, vector<int> &weight, int w, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    return w / weight[0] * profit[0];
  }

  if (dp[ind][w] != -1)
  {
    return dp[ind][w];
  }

  int notTake = func(ind - 1, profit, weight, w, dp);
  int take = 0;
  if (w >= weight[ind])
    take = profit[ind] + func(ind, profit, weight, w - weight[ind], dp);

  return dp[ind][w] = max(notTake, take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
  vector<vector<int>> dp(n, vector<int>(w + 1, -1));
  return func(n - 1, profit, weight, w, dp);
}

// tab
#include <bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
  vector<vector<int>> dp(n, vector<int>(w + 1, 0));

  for (int i = 0; i <= w; i++)
  {
    dp[0][i] = i / weight[0] * profit[0];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= w; j++)
    {
      int notTake = dp[i - 1][j];
      int take = 0;
      if (j >= weight[i])
        take = profit[i] + dp[i][j - weight[i]];
      dp[i][j] = max(take, notTake);
    }
  }

  return dp[n - 1][w];
}

// S.O
#include <bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
  vector<int> prev(w + 1, 0), curr(w + 1, 0);

  for (int i = 0; i <= w; i++)
  {
    prev[i] = i / weight[0] * profit[0];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= w; j++)
    {
      int notTake = prev[j];
      int take = 0;
      if (j >= weight[i])
        take = profit[i] + curr[j - weight[i]];
      curr[j] = max(take, notTake);
    }
    prev = curr;
  }

  return prev[w];
}

// Ultra S.O
#include <bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
  vector<int> prev(w + 1, 0), curr(w + 1, 0);

  for (int i = 0; i <= w; i++)
  {
    prev[i] = i / weight[0] * profit[0];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= w; j++)
    {
      int notTake = prev[j];
      int take = 0;
      if (j >= weight[i])
        take = profit[i] + prev[j - weight[i]];
      prev[j] = max(take, notTake);
    }
  }

  return prev[w];
}
