bool fun(int index, vector<int> num, int k, vector<vector<int>> &dp)
{
  if (k == 0)
  {
    return true;
  }

  if (index == 0)
  {
    return k == num[0];
  }

  if (dp[index][k] != -1)
  {
    return dp[index][k];
  }

  bool n = fun(index - 1, num, k, dp);
  bool m = false;
  if (k >= num[index])
    m = fun(index - 1, num, k - num[index], dp);
  return dp[index][k] = n || m;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return fun(n - 1, arr, k, dp);
}

// Tab
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }
  dp[0][arr[0]] = true;

  for (int i = 1; i < n; i++)
  {
    for (int tar = 1; tar <= k; tar++)
    {
      bool notTake = dp[i - 1][tar];
      bool take = false;
      if (tar >= arr[i])
        take = dp[i - 1][tar - arr[i]];
      dp[i][tar] = take || notTake;
    }
  }
  return dp[n - 1][k];
}

// S.O
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  vector<bool> prev(k + 1, false), curr(k + 1, false);
  prev[0] = curr[0] == true;
  if (arr[0] <= k)
    prev[arr[0]] = true;

  for (int i = 1; i < n; i++)
  {
    for (int tar = 1; tar <= k; tar++)
    {
      bool notTake = prev[tar];
      bool take = false;
      if (tar >= arr[i])
        take = prev[tar - arr[i]];
      curr[tar] = take || notTake;
    }
    prev = curr;
  }
  return prev[k];
}