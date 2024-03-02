#include <bits/stdc++.h>

int mod = (int)(1e9 + 7);
int findWaysUtil(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp,
                 int totSum, int d)
{
  if (ind < 0)
  {
    int secondHalf = totSum - sum;
    if (sum >= secondHalf)
      return (sum - secondHalf) == d;
    return 0;
  }

  if (dp[ind][sum] != -1)
    return dp[ind][sum];

  int take = findWaysUtil(ind - 1, sum + arr[ind], arr, dp, totSum, d);
  int notTake = findWaysUtil(ind - 1, sum, arr, dp, totSum, d);

  return dp[ind][sum] = (take + notTake) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
  int sum = accumulate(arr.begin(), arr.end(), 0);

  vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

  return findWaysUtil(n - 1, 0, arr, dp, sum, d);
}

// tab
int countPartitions(int n, int d, vector<int> &arr)
{
  int sum = accumulate(arr.begin(), arr.end(), 0);

  int k = (sum - d) / 2;
  if (sum - d < 0 || (sum - d) % 2)
    return false;
  vector<vector<int>> dp(n, vector<int>(k + 1, 0));

  dp[0][0] = (arr[0] == 0) ? 2 : 1;

  if (arr[0] != 0 && k >= arr[0])
    dp[0][arr[0]] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      int take = 0;
      if (j >= arr[i])
        take = dp[i - 1][j - arr[i]];

      int notTake = dp[i - 1][j];

      dp[i][j] = (take + notTake) % mod;
    }
  }

  return dp[n - 1][k];
}

// S.O
#include <bits/stdc++.h>

int mod = (int)(1e9 + 7);

int countPartitions(int n, int d, vector<int> &arr)
{
  int sum = accumulate(arr.begin(), arr.end(), 0);

  int k = (sum - d) / 2;
  if (sum - d < 0 || (sum - d) % 2)
    return false;
  vector<int> curr(k + 1, 0), prev(k + 1, 0);

  prev[0] = (arr[0] == 0) ? 2 : 1;

  if (arr[0] != 0 && k >= arr[0])
    prev[arr[0]] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      int take = 0;
      if (j >= arr[i])
        take = prev[j - arr[i]];

      int notTake = prev[j];

      curr[j] = (take + notTake) % mod;
    }
    prev = curr;
  }

  return prev[k];
}
