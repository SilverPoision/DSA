#include <bits/stdc++.h>

int f(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp, int fee)
{
  if (i >= n)
    return 0;

  if (dp[i][buy] != -1)
  {
    return dp[i][buy];
  }

  if (buy)
  {
    return dp[i][buy] = max(-prices[i] + f(i + 1, 0, prices, n, dp, fee), f(i + 1, buy, prices, n, dp, fee));
  }
  return dp[i][buy] = max(prices[i] - fee + f(i + 1, 1, prices, n, dp, fee), f(i + 1, buy, prices, n, dp, fee));
}

int maximumProfit(int n, int fee, vector<int> &prices)
{
  vector<vector<int>> dp(n, vector<int>(3, -1));
  return f(0, 1, prices, n, dp, fee);
}
