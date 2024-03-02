#include <bits/stdc++.h>
#define ll long long
long long findMaxAs(int N)
{
  if (N <= 6)
    return N;

  vector<ll> dp(N + 1, 0);

  for (int i = 1; i <= 6; i++)
  {
    dp[i] = i;
  }

  for (int k = 7; k <= N; k++)
  {
    for (ll i = k - 3; i >= 1; i--)
    {
      ll curr = (k - i - 1) * dp[i];
      dp[k] = max(dp[k], curr);
    }
  }

  return dp[N];
}