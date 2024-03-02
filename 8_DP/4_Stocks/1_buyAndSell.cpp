#include <bits/stdc++.h>

int stocks(int i, int j, vector<int> &prices, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
  {
    return 0;
  }

  if (i == 0 && j > 0)
  {
    return 0;
  }

  if (j == 0 && i > 0)
  {
    if (prices[i] > prices[j])
    {
      return prices[i] - prices[j];
    }
    else
    {
      return 0;
    }
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  int buy = max(prices[i] - prices[j], stocks(i - 1, j - 1, prices, dp));
  int notBuy = stocks(i, j - 1, prices, dp);

  return dp[i][j] = max(buy, notBuy);
}

int maximumProfit(vector<int> &prices)
{
  int n = prices.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return stocks(n - 1, n - 2, prices, dp);
}

// Iterative

#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
  int n = prices.size();
  int mini = prices[0];
  int profit = 0;
  for (int i = 1; i < n; i++)
  {
    int cost = prices[i] - mini;
    profit = max(profit, cost);
    mini = min(mini, prices[i]);
  }

  return profit;
}