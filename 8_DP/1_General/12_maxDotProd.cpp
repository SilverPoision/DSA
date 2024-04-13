int maxDotProduct(int n, int m, int a[], int b[])
{
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return solve(0, 0, n, m, a, b, dp);
}
// https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1

int solve(int i, int j, int n, int m, int a[], int b[], vector<vector<int>> &dp)
{
  if (j == m)
  {
    return 0;
  }
  if (i == n)
  {
    return INT_MIN;
  }
  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }
  int no_take = 0 + solve(i + 1, j, n, m, a, b, dp);
  int take = a[i] * b[j] + solve(i + 1, j + 1, n, m, a, b, dp);
  return dp[i][j] = max(no_take, take);
}
//================

class Solution
{

public:
  int solve(int i, int j, int a[], int b[], int n, int m, vector<vector<int>> &dp, int c)
  {
    if (i >= n || j >= m)
      return -1e9;

    if (dp[i][j] != -1e9)
      return dp[i][j];

    int take = a[i] * b[j] + solve(i + 1, j + 1, a, b, n, m, dp, c);
    int notTake = 0;
    if (c)
      notTake = solve(i + 1, j, a, b, n, m, dp, c - 1);

    return dp[i][j] = max(take, notTake);
  }
  int maxDotProduct(int n, int m, int a[], int b[])
  {
    // Your code goes here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
    return solve(0, 0, a, b, n, m, dp, n - m);
  }
};

class Solution
{
public:
  int solve(int i, int canPut, int n, int a[], int b[], int m, vector<vector<int>> &dp)
  {
    if (i >= n)
    {
      return 0;
    }

    if (i >= m && (n - i) == canPut)
      return 0;

    if (dp[i][canPut] != -1)
      return dp[i][canPut];

    int take = 0;
    if (canPut > 0)
    {
      take = solve(i + 1, canPut - 1, n, a, b, m, dp);
    }
    int notTake = a[i] * b[i - ((n - m) - canPut)] + solve(i + 1, canPut, n, a, b, m, dp);

    return dp[i][canPut] = max(take, notTake);
  }
  int maxDotProduct(int n, int m, int a[], int b[])
  {
    // Your code goes here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int canPut = n - m;
    return solve(0, canPut, n, a, b, m, dp);
  }
};
