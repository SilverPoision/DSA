#include <bits/stdc++.h>

int stocks(int i, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
  if (i == n)
    return 0;
  if (cap == 0)
    return 0;

  if (dp[i][buy][cap] != -1)
  {
    return dp[i][buy][cap];
  }

  int profit = 0;

  if (buy)
  {
    profit = max(-prices[i] + stocks(i + 1, 0, cap, prices, n, dp), stocks(i + 1, 1, cap, prices, n, dp));
  }
  else
  {
    profit = max(prices[i] + stocks(i + 1, 1, cap - 1, prices, n, dp), stocks(i + 1, 0, cap, prices, n, dp));
  }

  return dp[i][buy][cap] = profit;
}

int maxProfit(vector<int> &prices, int n)
{
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
  return stocks(0, 1, 2, prices, n, dp);
}

// Tab
#include <bits/stdc++.h>

int maxProfit(vector<int> &prices, int n)
{
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(3, 0)));

  for (int currDay = 0; currDay <= prices.size(); currDay++)
  {
    for (int buyFlag = 0; buyFlag <= 1; buyFlag++)
    {
      dp[currDay][buyFlag][0] = 0;
    }
  }

  for (int capacity = 0; capacity < 3; capacity++)
  {
    for (int buyFlag = 0; buyFlag <= 1; buyFlag++)
    {
      dp[n][buyFlag][capacity] = 0;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int buy = 0; buy < 2; buy++)
    {
      for (int cap = 1; cap <= 2; cap++)
      {
        int profit = 0;
        if (buy)
        {
          profit = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
        }
        else
        {
          profit = max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
        }

        dp[i][buy][cap] = profit;
      }
    }
  }
  return dp[0][1][2];
}

// S.O
#include <bits/stdc++.h>

int maxProfit(vector<int> &prices, int n)
{
  vector<vector<int>> prev(3, vector<int>(3, 0)), curr(3, vector<int>(3, 0));

  for (int currDay = 0; currDay <= prices.size(); currDay++)
  {
    for (int buyFlag = 0; buyFlag <= 1; buyFlag++)
    {
      prev[buyFlag][0] = 0;
    }
  }

  for (int capacity = 0; capacity < 3; capacity++)
  {
    for (int buyFlag = 0; buyFlag <= 1; buyFlag++)
    {
      prev[buyFlag][capacity] = 0;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int buy = 0; buy < 2; buy++)
    {
      for (int cap = 1; cap <= 2; cap++)
      {
        int profit = 0;
        if (buy)
        {
          profit = max(-prices[i] + prev[0][cap], prev[1][cap]);
        }
        else
        {
          profit = max(prices[i] + prev[1][cap - 1], prev[0][cap]);
        }

        curr[buy][cap] = profit;
      }
    }
    prev = curr;
  }
  return prev[1][2];
}