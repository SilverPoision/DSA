#include <bits/stdc++.h>

int minSubsetSumDifference(vector<int> &arr, int n)
{
  int totSum = 0;
  for (auto it : arr)
  {
    totSum += it;
  }

  vector<bool> prev(totSum + 1, 0), curr(totSum + 1, 0); // this shows if a target value of k is possible at the ith index or not.

  prev[0] = curr[0] = true;
  prev[arr[0]] = true;

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= totSum; j++)
    {
      bool notTake = prev[j];
      bool take = false;
      if (j >= arr[i])
        take = prev[j - arr[i]];
      curr[j] = notTake || take;
    }
    prev = curr;
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum / 2; i++)
  {
    if (prev[i] == true)
    {
      int sub = totSum - i;           // total sum in partition 1
      mini = min(mini, abs(sub - i)); // total sum in partition 2
    }
  }

  return mini;
}

int dfs(int ind, int upperBound, vector<int> &nums, vector<vector<int>> &dp)
{
  if (ind > nums.size() - 1)
    return 0;

  if (dp[ind][upperBound] != -1)
    return dp[ind][upperBound];

  int notTaken = dfs(ind + 1, upperBound, nums, dp);

  int taken = -1e8;
  if (nums[ind] <= upperBound)
  {
    taken = nums[ind] + dfs(ind + 1, upperBound - nums[ind], nums, dp);
  }

  return dp[ind][upperBound] = std::max(notTaken, taken);
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
  int sum = 0;
  for (int i = 0; i < n; ++i)
    sum += arr[i];

  vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
  return std::abs(sum - 2 * dfs(0, sum / 2, arr, dp));
}