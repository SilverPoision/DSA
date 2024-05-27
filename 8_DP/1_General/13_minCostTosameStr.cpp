class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1
  int dp[1001][1001];
  int solve(int i, int j, string &x, string &y, int costx, int costy)
  {
    if (i == x.size() || j == y.size())
    {
      if (i < x.size())
        return costx * (x.size() - i);
      return costy * (y.size() - j);
    }
    if (dp[i][j] != -1)
      return dp[i][j];

    if (x[i] == y[j])
    {
      return solve(i + 1, j + 1, x, y, costx, costy);
    }

    return dp[i][j] = min(costx + solve(i + 1, j, x, y, costx, costy), costy + solve(i, j + 1, x, y, costx, costy));
  }
  int findMinCost(string x, string y, int costX, int costY)
  {
    // Your code goes here
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, x, y, costX, costY);
  }
};

// Tab
class Solution
{

public:
  int dp[1001][1001];

  int findMinCost(string x, string y, int costx, int costy)
  {
    // Your code goes here
    memset(dp, 0, sizeof(dp));
    // return solve(0, 0, x,y,costX, costY);

    int n = x.size();
    int m = y.size();

    for (int i = 0; i < m; i++)
    {
      dp[n][i] = costy * (m - i);
    }
    for (int i = 0; i < n; i++)
    {
      dp[i][m] = costx * (n - i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        if (x[i] == y[j])
        {
          dp[i][j] = dp[i + 1][j + 1];
          continue;
        }

        dp[i][j] = min(costx + dp[i + 1][j], costy + dp[i][j + 1]);
      }
    }

    return dp[0][0];
  }
};

// SO
class Solution
{

public:
  int dp[1001];

  int findMinCost(string x, string y, int costx, int costy)
  {
    // Your code goes here
    // return solve(0, 0, x,y,costX, costY);
    int n = x.size();
    int m = y.size();

    vector<int> curr(m + 1, 0), prev(m + 1, 0);

    for (int i = 0; i < m; i++)
    {
      prev[i] = costy * (m - i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
      curr[m] = costx * (n - i);
      for (int j = m - 1; j >= 0; j--)
      {
        if (x[i] == y[j])
        {
          curr[j] = prev[j + 1];
        }
        else
        {
          curr[j] = min(costx + prev[j], costy + curr[j + 1]);
        }
      }
      prev = curr;
    }

    return prev[0];
  }
};