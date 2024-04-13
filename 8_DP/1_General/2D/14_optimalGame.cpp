class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
  long long solve(int i, int j, int arr[], vector<vector<int>> &dp)
  {
    if (i > j)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int f = arr[i] + solve(i + 2, j, arr, dp);
    int f2 = arr[i] + solve(i + 1, j - 1, arr, dp);
    int s = arr[j] + solve(i, j - 2, arr, dp);
    int s2 = arr[j] + solve(i + 1, j - 1, arr, dp);

    return dp[i][j] = max(min(f, f2), min(s, s2));
  }
  long long maximumAmount(int n, int arr[])
  {
    // Your code here
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, n - 1, arr, dp);
  }
};