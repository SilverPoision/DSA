#include <bits/stdc++.h>

int f(int i, int tranNo, int n, vector<int> &prices, int k, vector<vector<int>> &dp)
{
  if (i == n || tranNo == 2 * k)
    return 0;

  if (dp[i][tranNo] != -1)
  {
    return dp[i][tranNo];
  }

  if (tranNo % 2 == 0)
  {
    return dp[i][tranNo] = max(-prices[i] + f(i + 1, tranNo + 1, n, prices, k, dp), f(i + 1, tranNo, n, prices, k, dp));
  }
  return dp[i][tranNo] = max(prices[i] + f(i + 1, tranNo + 1, n, prices, k, dp), f(i + 1, tranNo, n, prices, k, dp));
}

int maximumProfit(vector<int> &prices, int n, int k)
{
  vector<vector<int>> dp(n, vector<int>(2 * k, -1));
  return f(0, 0, n, prices, k, dp);
}

// It can also be done by buyans sell 3