int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  if (target == 0)
  {
    return 1;
  }

  if (ind == 0)
  {
    return target == arr[0];
  }

  if (dp[ind][target] != -1)
    return dp[ind][target];

  int notTaken = findWaysUtil(ind - 1, target, arr, dp);

  int taken = 0;
  if (arr[ind] <= target)
    taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int k)
{
  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return findWaysUtil(n - 1, k, num, dp);
}

// tab
int findWays(vector<int> &num, int tar)
{
  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = 1;
  }
  if (num[0] <= tar)
    dp[0][num[0]] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= tar; j++)
    {
      int notTake = dp[i - 1][j];
      int take = 0;
      if (num[i] <= j)
        take = dp[i - 1][j - num[i]];
      dp[i][j] = notTake + take;
    }
  }
  return dp[n - 1][tar];
}

// S.O
#include <bits/stdc++.h>

int findWays(vector<int> &num, int tar)
{
  int n = num.size();
  vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
  prev[0] = curr[0] = 1;
  if (num[0] <= tar)
    prev[num[0]] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= tar; j++)
    {
      int notTake = prev[j];
      int take = 0;
      if (num[i] <= j)
        take = prev[j - num[i]];
      curr[j] = notTake + take;
    }
    prev = curr;
  }
  return prev[tar];
}

// If quest contains 0 then
int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    if (sum == 0 && arr[0] == sum)
      return 2;
    if (sum == 0 || sum == arr[0])
      return 1;

    return 0;
  }

  if (dp[ind][target] != -1)
    return dp[ind][target];

  int notTaken = findWaysUtil(ind - 1, target, arr, dp);

  int taken = 0;
  if (arr[ind] <= target)
    taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int k)
{
  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return findWaysUtil(n - 1, k, num, dp);
}
