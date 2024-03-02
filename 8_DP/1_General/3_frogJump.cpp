#include <bits/stdc++.h>

// memoization
#include <bits/stdc++.h>

int recur(int n, vector<int> &heights, vector<int> &dp)
{
  if (n == 0)
  {
    return 0;
  }

  if (dp[n] != -1)
    return dp[n];

  int left = recur(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
  int right = INT_MAX;
  if (n > 1)
  {
    right = recur(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
  }

  dp[n] = min(left, right);
  return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n + 1, -1);
  return recur(n - 1, heights, dp);
}

// Tabulation

int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n, -1);
  dp[0] = 0;
  for (int k = 1; k < n; k++)
  {
    if (dp[k] != -1)
    {
      return dp[k];
    }
    int left = dp[k - 1] + abs(heights[k] - heights[k - 1]);
    int right = INT_MAX;
    if (k > 1)
    {
      right = dp[k - 2] + abs(heights[k] - heights[k - 2]);
    }
    dp[k] = min(left, right);
  }
  return dp[n - 1];
}

// S.O
#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
  int prev2 = 0, prev = 0;
  for (int k = 1; k < n; k++)
  {
    int fs = prev + abs(heights[k] - heights[k - 1]);
    int sc = INT_MAX;
    if (k > 1)
    {
      sc = prev2 + abs(heights[k] - heights[k - 2]);
    }
    int curr = min(fs, sc);
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

// K jump

// Memo
int f(int i, vector<int> &height, int k, vector<int> &dp)
{
  if (i == 0)
    return 0;
  if (i == 1)
    return abs(height[i] - height[i - 1]);

  if (dp[i] != -1)
    return dp[i];

  int mini = 1e9;

  for (int j = 1; j <= k; j++)
  {
    if (i - j >= 0)
      mini = min(mini, abs(height[i] - height[i - j]) + f(i - j, height, k, dp));
  }

  dp[i] = mini;
}

#include <bits/stdc++.h>
// O Jumps

int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n, -1);
  dp[0] = 0;
  for (int k = 1; k < n; k++)
  {
    int minSteps = INT_MAX;
    for (int o = 1; o <= t; o++)
    {
      if (k - o >= 0)
      {
        jump = dp[k - o] + abs(heights[k] - height[k - o]);
        minSteps = min(minSteps, jumps);
      }
    }
    dp[k] = minSteps;
  }
  return dp[n - 1];
}
