#include <bits/stdc++.h>

int f(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
{
  if (i >= n)
    return 0;

  if (dp[i][buy] != -1)
  {
    return dp[i][buy];
  }

  if (buy)
  {
    return dp[i][buy] = max(-prices[i] + f(i + 1, 0, prices, n, dp), f(i + 1, buy, prices, n, dp));
  }
  return dp[i][buy] = max(prices[i] + f(i + 2, 1, prices, n, dp), f(i + 1, buy, prices, n, dp));
}

int stockProfit(vector<int> &prices)
{
  int n = prices.size();
  vector<vector<int>> dp(n, vector<int>(3, -1));
  return f(0, 1, prices, n, dp);
}