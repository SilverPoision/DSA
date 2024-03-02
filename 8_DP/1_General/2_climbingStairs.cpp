#include <bits/stdc++.h>

int recur(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }

  int left = recur(n - 1);
  int right = recur(n - 2);

  return left + right;
}

int countDistinctWays(int nStairs)
{
  return recur(nStairs);
}

// Memo
#include <bits/stdc++.h>
const int mod = 1e9 + 7;

int recur(int n, vector<int> &dp)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }

  if (dp[n] != 1e9)
  {
    return dp[n];
  }

  int left = recur(n - 1, dp) % mod;
  int right = recur(n - 2, dp) % mod;

  return dp[n] = left + right % mod;
}

int countDistinctWays(int nStairs)
{
  vector<int> dp(nStairs + 1, 1e9);
  return recur(nStairs, dp) % mod;
}