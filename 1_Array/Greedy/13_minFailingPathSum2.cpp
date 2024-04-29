// Optimal
class Solution
{
public:
  // https://www.youtube.com/watch?v=LCC0gTGEK1Y
  int minFallingPathSum(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int ans = INT_MAX;

    pair<int, int> s = {0, -1}, ss = {0, -1};

    for (int i = 0; i < n; i++)
    {
      pair<int, int> cs = {INT_MAX, -1}, css = {INT_MAX, -1};

      for (int j = 0; j < n; j++)
      {
        auto minToTake = s.second != j ? s : ss;
        if (grid[i][j] + minToTake.first < cs.first)
        {
          css = cs;
          cs = {grid[i][j] + minToTake.first, j};
        }
        else if (grid[i][j] + minToTake.first < css.first)
        {
          css = {grid[i][j] + minToTake.first, j};
        }
        if (i == n - 1)
        {
          ans = min({ans, cs.first, css.first});
        }
      }
      s = cs;
      ss = css;
    }

    return ans;
  }
};

class Solution
{
public:
  // https://leetcode.com/problems/minimum-falling-path-sum-ii/
  int solve(int i, vector<vector<int>> &grid, int last, vector<vector<int>> &dp)
  {
    if (i == grid.size())
    {
      return 0;
    }

    if (dp[i][last] != -1)
      return dp[i][last];

    int mini = 1e9;
    for (int k = 0; k < grid.size(); k++)
    {
      if (k == last)
        continue;
      mini = min(mini, grid[i][k] + solve(i + 1, grid, k, dp));
    }

    return dp[i][last] = mini;
  }
  int minFallingPathSum(vector<vector<int>> &grid)
  {
    vector<vector<int>> dp(grid.size(), vector<int>(202, -1));
    int res = solve(0, grid, 201, dp);
    return res;
  }
};