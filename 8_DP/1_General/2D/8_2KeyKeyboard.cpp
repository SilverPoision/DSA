class Solution
{
public:
  int f(int a_onscreen, int n, int a_onClipboard, vector<vector<int>> &dp)
  {
    if (a_onscreen > n)
      return 1e9;
    if (a_onscreen == n)
      return 0;

    if (dp[a_onscreen][a_onClipboard] != -1)
      return dp[a_onscreen][a_onClipboard];

    if (a_onClipboard == 0)
      return 1 + f(a_onscreen, n, a_onscreen, dp);
    if (a_onscreen == a_onClipboard)
      return 1 + f(a_onClipboard + a_onscreen, n, a_onClipboard, dp);

    int copy = f(a_onscreen, n, a_onscreen, dp);
    int paste = f(a_onClipboard + a_onscreen, n, a_onClipboard, dp);

    return dp[a_onscreen][a_onClipboard] = 1 + min(copy, paste);
  }
  int minSteps(int n)
  {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(1, n, 0, dp);
  }
};

// Recursion
class Solution
{
public:
  int f(int l, int n, int c, vector<vector<int>> &dp)
  {
    if (l == n)
      return 0;

    if (dp[l][c] != -1)
      return dp[l][c];

    int copy = 1e9, paste = 1e9;
    if (l != c)
      copy = f(l, n, l, dp);
    if (l + c <= n)
      paste = f(l + c, n, c, dp);

    return dp[l][c] = 1 + min(copy, paste);
  }
  int minSteps(int n)
  {
    if (n == 1)
      return 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return 1 + f(1, n, 1, dp);
  }
};

// Prime N0 Approach

#include <bits/stdc++.h>
using namespace std;

int minSteps(int N)
{
  // Stores the count of steps needed
  int ans = 0;

  // Traverse over the range [2, N]
  for (int d = 2; d * d <= N; d++)
  {

    // Iterate while N is divisible
    // by d
    while (N % d == 0)
    {

      // Increment the value of
      // ans by d
      ans += d;

      // Divide N by d
      N /= d;
    }
  }

  // If N is not 1
  if (N != 1)
  {
    ans += N;
  }

  // Return the ans
  return ans;
}

// Driver Code
int main()
{
  int N = 3;
  cout << minSteps(N);

  return 0;
}

// Tab
class Solution
{
public:
  int minSteps(int n)
  {
    if (n == 1)
      return 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int l = n - 1; l >= 0; l--)
    {
      for (int c = n - 1; c >= 0; c--)
      {
        int copy = 1e9, paste = 1e9;

        if (l != c)
          copy = dp[l][l];
        if (l + c <= n)
          paste = dp[l + c][c];
        dp[l][c] = 1 + min(copy, paste);
      }
    }
    return 1 + dp[1][1];
  }
};