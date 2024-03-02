class Solution
{
public:
  int f(int i, int diff, vector<int> &rods, vector<vector<int>> &dp)
  {
    if (i == rods.size())
    {
      if (diff == 0)
        return 0;
      return -1e9;
    }

    if (dp[i][diff + 5000] != -1)
      return dp[i][diff + 5000];

    int take1 = rods[i] + f(i + 1, diff - rods[i], rods, dp);
    int take2 = rods[i] + f(i + 1, diff + rods[i], rods, dp);
    int notTake = f(i + 1, diff, rods, dp);

    return dp[i][diff + 5000] = max({take1, take2, notTake});
  }
  int tallestBillboard(vector<int> &rods)
  {
    vector<vector<int>> dp(rods.size() + 1, vector<int>(10001, -1));
    return f(0, 0, rods, dp) / 2;
  }
};

// try to understand the tabulation