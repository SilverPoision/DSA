// Greedy style solution - Printing LIS
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
  vector<int> dp(n, 1);
  vector<int> previous(n, 0);

  int maxi = 1;
  int lastIndex = -1;

  for (int index = 0; index < n; index++)
  {
    previous[index] = index;
    for (int prev = 0; prev < index; prev++)
    {
      if (arr[prev] < arr[index] && dp[index] < 1 + dp[prev])
      {
        dp[index] = 1 + dp[prev];

        previous[index] = prev;
      }
    }
    if (maxi < dp[index])
    {
      maxi = dp[index];
      lastIndex = index;
    }
  }

  vector<int> ans;

  ans.push_back(arr[lastIndex]);

  while (previous[lastIndex] != lastIndex)
  {
    lastIndex = previous[lastIndex];
    ans.push_back(arr[lastIndex]);
  }

  reverse(ans.begin(), ans.end());

  for (auto it : ans)
  {
    cout << it << " ";
  }

  cout << endl;

  return maxi;
}
