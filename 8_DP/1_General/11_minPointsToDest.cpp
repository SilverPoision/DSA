class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1
  int solve(int i, int j, vector<vector<int>> &p, int n, int m, vector<vector<int>> &dp)
  {
    if (i >= n || j >= m)
      return -1e9;
    if (i == n - 1 && j == m - 1)
    {
      return min(p[i][j], 0);
    }

    if (dp[i][j] != -1e9)
      return dp[i][j];

    int down = p[i][j] + solve(i + 1, j, p, n, m, dp);
    int right = p[i][j] + solve(i, j + 1, p, n, m, dp);

    down = min(down, 0);
    right = min(right, 0);

    return dp[i][j] = max(down, right);
  }
  int minPoints(int n, int m, vector<vector<int>> points)
  {
    // Your code goes here
    vector<vector<int>> dp(n, vector<int>(m, -1e9));
    int val = solve(0, 0, points, n, m, dp);

    return abs(val) + 1;
  }
};

//============================================

class Solution
{
public:
  bool solve(int i, int j, vector<vector<int>> &p, int n, int m, int mid)
  {
    if (i >= n || i < 0 || j >= m || j < 0 || mid <= 0)
      return false;
    if (i == n - 1 && j == m - 1)
    {
      return (mid + p[i][j]) > 0;
    }
    // cout << mid << i << j << endl;
    // bool f = false;
    if ((mid + p[i][j]) > 0)
    {
      if (solve(i + 1, j, p, n, m, mid + p[i][j]))
        return true;
      if (solve(i, j + 1, p, n, m, mid + p[i][j]))
        return true;
    }

    return false;
  }
  int minPoints(int n, int m, vector<vector<int>> points)
  {
    // Your code goes here
    int l = 1, h = 1e9;
    int ans = 1e9;

    while (l <= h)
    {
      int mid = (h + l) / 2;

      if (solve(0, 0, points, n, m, mid) == true)
      {
        // cout << solve(0,0,points, n, m, mid) << " " << mid << endl;
        h = mid - 1;
        ans = min(ans, mid);
      }
      else
      {
        l = mid + 1;
      }
    }

    return ans;
  }
};