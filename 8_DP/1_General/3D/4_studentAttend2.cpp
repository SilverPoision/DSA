class Solution
{
public:
  int MOD = 1e9 + 7;

  int checkRecord(int k)
  {
    vector<vector<int>> prev(4, vector<int>(3, 0));
    vector<vector<int>> curr(4, vector<int>(3, 0));

    for (int i = 0; i <= 2; i++)
    {
      for (int j = 0; j <= 1; j++)
      {
        prev[i][j] = 1;
      }
    }

    for (int n = 1; n <= k; n++)
    {
      for (int abs = 0; abs < 2; abs++)
      {
        for (int late = 0; late < 3; late++)
        {
          int ans = 0;

          ans = (ans + prev[late + 1][abs]) % MOD;
          ans = (ans + prev[0][abs + 1]) % MOD;
          ans = (ans + prev[0][abs]) % MOD;

          curr[late][abs] = ans % MOD;
        }
      }
      prev = curr;
    }

    return prev[0][0];
  }
};

class Solution
{
public:
  // https://leetcode.com/problems/student-attendance-record-ii/?envType=daily-question&envId=2024-05-26
  int MOD = 1e9 + 7;
  int solve(int n, int late, int abs, vector<vector<vector<int>>> &dp)
  {
    if (late > 2 || abs > 1)
      return 0;

    if (n == 0)
    {
      return 1;
    }

    if (dp[late][abs][n] != -1)
      return dp[late][abs][n];

    int ans = 0;

    ans = (ans + solve(n - 1, late + 1, abs, dp)) % MOD;
    ans = (ans + solve(n - 1, 0, abs + 1, dp)) % MOD;
    ans = (ans + solve(n - 1, 0, abs, dp)) % MOD;

    return dp[late][abs][n] = ans % MOD;
  }

  int checkRecord(int n)
  {
    vector<vector<vector<int>>> dp(
        3, vector<vector<int>>(2, vector<int>(n + 1, -1)));
    return solve(n, 0, 0, dp) % MOD;
  }
};