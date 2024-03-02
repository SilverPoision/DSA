#include <bits/stdc++.h>

int func(int ind, vector<int> coins, int p, int n, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    if (p % coins[ind])
    {
      return 1e9;
    }
    else
    {
      return p / coins[ind];
    }
  }

  if (dp[ind][p] != -1)
  {
    return dp[ind][p];
  }

  int notTake = func(ind - 1, coins, p, n, dp);
  int take = 1e9;
  if (p >= coins[ind])
    take = 1 + func(ind, coins, p - coins[ind], n, dp);

  return dp[ind][p] = min(notTake, take);
}

int minimumElements(vector<int> &nums, int p)
{
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(p + 1, -1));
  int ans = func(n - 1, nums, p, n, dp);
  if (ans >= 1e9)
  {
    return -1;
  }
  else
  {
    return ans;
  }
}

// Tab
#include <bits/stdc++.h>

int minimumElements(vector<int> &nums, int x)
{
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(x + 1, 0));

  for (int k = 0; k <= x; k++)
  {
    if (k % nums[0] == 0)
    {
      dp[0][k] = k / nums[0];
    }
    else
    {
      dp[0][k] = 1e9;
    }
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int k = 0; k <= x; k++)
    {
      int notTake = dp[ind - 1][k];
      int take = INT_MAX;
      if (k >= nums[ind])
        take = 1 + dp[ind][k - nums[ind]];
      dp[ind][k] = min(take, notTake);
    }
  }

  int ans = dp[n - 1][x];
  if (ans >= 1e9)
  {
    return -1;
  }
  else
  {
    return ans;
  }
}

// S.O
#include <bits/stdc++.h>

int minimumElements(vector<int> &nums, int x)
{
  int n = nums.size();
  vector<int> prev(x + 1, 0), curr(x + 1, 0);

  for (int k = 0; k <= x; k++)
  {
    if (k % nums[0] == 0)
    {
      prev[k] = k / nums[0];
    }
    else
    {
      prev[k] = 1e9;
    }
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int k = 0; k <= x; k++)
    {
      int notTake = prev[k];
      int take = INT_MAX;
      if (k >= nums[ind])
        take = 1 + curr[k - nums[ind]];
      curr[k] = min(take, notTake);
    }
    prev = curr;
  }

  int ans = prev[x];
  if (ans >= 1e9)
  {
    return -1;
  }
  else
  {
    return ans;
  }
}