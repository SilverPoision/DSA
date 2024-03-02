#include <bits/stdc++.h>

int f(int ind, int *arr, int prev, vector<vector<int>> &dp, int n)
{
  if (ind == n)
  {
    return 0;
  }

  if (dp[ind][prev + 1] != -1)
  {
    return dp[ind][prev + 1];
  }

  int notTake = f(ind + 1, arr, prev, dp, n);
  int take = 0;
  if (prev == -1 || arr[prev] < arr[ind])
  {
    take = 1 + f(ind + 1, arr, ind, dp, n);
  }
  return dp[ind][prev + 1] = max(take, notTake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  return f(0, arr, -1, dp, n);
}

// Tab
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int prev = ind - 1; prev >= -1; prev--)
    {
      int notTake = dp[ind + 1][prev + 1];
      int take = 0;
      if (prev == -1 || arr[prev] < arr[ind])
      {
        take = 1 + dp[ind + 1][ind + 1];
      }
      dp[ind][prev + 1] = max(take, notTake);
    }
  }
  return dp[0][-1 + 1];
}

// S.O
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
  vector<int> pre(n + 1, 0), curr(n + 1, 0);

  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int prev = ind - 1; prev >= -1; prev--)
    {
      int notTake = pre[prev + 1];
      int take = 0;
      if (prev == -1 || arr[prev] < arr[ind])
      {
        take = 1 + pre[ind + 1];
      }
      curr[prev + 1] = max(take, notTake);
    }
    pre = curr;
  }
  return pre[-1 + 1];
}

// Optimal or greedy
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
  vector<int> dp(n, 1);

  int maxi = 1;

  for (int ind = 0; ind < n; ind++)
  {
    for (int prev = 0; prev < ind; prev++)
    {
      if (arr[prev] < arr[ind])
      {
        dp[ind] = max(dp[ind], 1 + dp[prev]);
      }
    }
    maxi = max(maxi, dp[ind]);
  }

  return maxi;
}

// Binary Search with O(n log n)
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
  vector<int> temp;
  temp.push_back(arr[0]);

  for (int i = 1; i < n; i++)
  {
    if (arr[i] > temp.back())
    {
      temp.push_back(arr[i]);
    }
    else
    {
      int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
      temp[ind] = arr[i];
    }
  }

  return temp.size();
}
