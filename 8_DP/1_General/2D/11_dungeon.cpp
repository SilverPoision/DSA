class Solution
{
public:
  // https://www.youtube.com/watch?v=LbC0ejgACkE
  int f(int i, int j, vector<vector<int>> &dun, vector<vector<int>> &dp)
  {
    if (i == dun.size() - 1 && j == dun[0].size() - 1)
    {
      return (dun[i][j] <= 0) ? -dun[i][j] + 1 : 1;
    }

    if (i == dun.size() || j == dun[0].size())
      return 1e9;

    if (dp[i][j] != 1e9)
      return dp[i][j];

    int down = f(i + 1, j, dun, dp);
    int right = f(i, j + 1, dun, dp);

    int minHealthReq = min(down, right) - dun[i][j];

    return dp[i][j] = (minHealthReq <= 0) ? 1 : minHealthReq;
  }
  int calculateMinimumHP(vector<vector<int>> &dun)
  {
    int n = dun.size();
    int m = dun[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 1e9)); // at the i,j position what amount of helth we need to survive.
    return f(0, 0, dun, dp);
  }
};

// Tab
class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>> &dun)
  {
    int n = dun.size();
    int m = dun[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    dp[n - 1][m] = 1;
    dp[n][m - 1] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        int down = dp[i + 1][j];
        int right = dp[i][j + 1];

        int minHealthReq = min(down, right) - dun[i][j];

        dp[i][j] = (minHealthReq <= 0) ? 1 : minHealthReq;
      }
    }

    return dp[0][0];
  }
};