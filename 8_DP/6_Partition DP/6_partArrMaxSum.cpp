#include <bits/stdc++.h>

int f(int i, int n, vector<int> &nums, int k, vector<int> &dp)
{
  if (i == n)
    return 0;

  if (dp[i] != -1)
  {
    return dp[i];
  }

  int maxi = -1e9;
  int maxi2 = 0;
  int len = 0;
  for (int ind = i; ind < min(n, i + k); ind++)
  {
    len++;
    maxi = max(maxi, nums[ind]);
    int parts = maxi * len + f(ind + 1, n, nums, k, dp);
    maxi2 = max(parts, maxi2);
  }
  return dp[i] = maxi2;
}

int maximumSubarray(vector<int> &num, int k)
{
  vector<int> dp(num.size() + 1, -1);
  return f(0, num.size(), num, k, dp);
}

// Tab
#include <bits/stdc++.h>

int maximumSubarray(vector<int> &nums, int k)
{
  int n = nums.size();
  vector<int> dp(n + 1, 0);

  for (int i = n - 1; i >= 0; i--)
  {
    int maxi = -1e9;
    int maxi2 = 0;
    int len = 0;
    for (int ind = i; ind < min(n, i + k); ind++)
    {
      len++;
      maxi = max(maxi, nums[ind]);
      int parts = maxi * len + dp[ind + 1];
      maxi2 = max(parts, maxi2);
    }
    dp[i] = maxi2;
  }
  return dp[0];
}