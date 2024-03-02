// BackTracking
class Solution
{
public:
  int maxi = 0;
  void toUp(int i, int j, int &n, vector<vector<int>> &grid, int cherry)
  {
    if (i == 0 && j == 0)
    {
      maxi = max(maxi, cherry);
      return;
    }
    if (i == -1 || j == -1 || grid[i][j] == -1)
      return;

    int chCurr = grid[i][j];
    grid[i][j] = 0;
    toUp(i - 1, j, n, grid, cherry + chCurr);
    toUp(i, j - 1, n, grid, cherry + chCurr);
    grid[i][j] = chCurr;
  }

  void toDown(int i, int j, int &n, vector<vector<int>> &grid, int cherry)
  {
    if (i == n - 1 && j == n - 1)
    {
      toUp(i, j, n, grid, cherry);
      return;
    }

    if (i == n || j == n || grid[i][j] == -1)
      return;

    int chCurr = grid[i][j];
    grid[i][j] = 0;
    toDown(i + 1, j, n, grid, cherry + chCurr);
    toDown(i, j + 1, n, grid, cherry + chCurr);
    grid[i][j] = chCurr;
  }
  int cherryPickup(vector<vector<int>> &grid)
  {
    int n = grid.size();
    if (n == 1)
      return grid[0][0] == -1 ? 0 : grid[0][0];
    toDown(0, 0, n, grid, 0);
    return maxi;
  }
};

int main()
{
  vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
  Solution s = Solution();
  cout << s.cherryPickup(grid);
  return 0;
}

// DP Memo
class Solution
{
public:
  bool hit = false;
  int f(int i1, int j1, int i2, int j2, vector<vector<int>> &grid, int n, vector<vector<vector<vector<int>>>> &dp)
  {
    if (i1 >= n || j1 >= n || i2 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
      return -1e9;

    if (i1 == n - 1 && j1 == n - 1)
    {
      hit = true;
      return grid[i1][j1];
    }

    if (dp[i1][j1][i2][j2] != -1)
      return dp[i1][j1][i2][j2];

    int cherry = 0;
    if (i1 == i2 && j1 == j2)
    {
      cherry = grid[i1][j1];
    }
    else
    {
      cherry = grid[i1][j1] + grid[i2][j2];
    }

    int hh = f(i1, j1 + 1, i2, j2 + 1, grid, n, dp);
    int hv = f(i1, j1 + 1, i2 + 1, j2, grid, n, dp);
    int vv = f(i1 + 1, j1, i2 + 1, j2, grid, n, dp);
    int vh = f(i1 + 1, j1, i2, j2 + 1, grid, n, dp);

    cherry += max(hh, max(hv, max(vv, vh)));
    return dp[i1][j1][i2][j2] = cherry;
  }

  int cherryPickup(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
    int res = f(0, 0, 0, 0, grid, n, dp);
    return hit == true ? res : 0;
  }
};

// S.O
class Solution
{
public:
  bool hit = false;
  int f(int i1, int j1, int i2, vector<vector<int>> &grid, int n, vector<vector<vector<int>>> &dp)
  {
    int j2 = i1 + j1 - i2;
    if (i1 >= n || j1 >= n || i2 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
      return -1e9;

    if (i1 == n - 1 && j1 == n - 1)
    {
      hit = true;
      return grid[i1][j1];
    }

    if (dp[i1][j1][i2] != -1)
      return dp[i1][j1][i2];

    int cherry = 0;
    if (i1 == i2 && j1 == j2)
    {
      cherry = grid[i1][j1];
    }
    else
    {
      cherry = grid[i1][j1] + grid[i2][j2];
    }

    int hh = f(i1, j1 + 1, i2, grid, n, dp);
    int hv = f(i1, j1 + 1, i2 + 1, grid, n, dp);
    int vv = f(i1 + 1, j1, i2 + 1, grid, n, dp);
    int vh = f(i1 + 1, j1, i2, grid, n, dp);

    cherry += max(hh, max(hv, max(vv, vh)));
    return dp[i1][j1][i2] = cherry;
  }

  int cherryPickup(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    int res = f(0, 0, 0, grid, n, dp);
    return hit == true ? res : 0;
  }
};

// Tab
class Solution
{
public:
  int cherryPickup(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));

    for (int i1 = n; i1 >= 0; i1--)
    {
      for (int j1 = n; j1 >= 0; j1--)
      {
        for (int i2 = n; i2 >= 0; i2--)
        {
          int j2 = i1 + j1 - i2;
          if (j2 < 0 || j2 > n)
            continue;

          if (i1 == n - 1 && j1 == n - 1)
          {
            dp[i1][j1][i2] = grid[i1][j1];
          }
          else if (i1 == n || j1 == n || i2 == n || j2 == n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
          {
            dp[i1][j1][i2] = INT_MIN;
          }
          else
          {
            int cherry = 0;
            if (i1 == i2 && j1 == j2)
            {
              cherry = grid[i1][j1];
            }
            else
            {
              cherry = grid[i1][j1] + grid[i2][j2];
            }

            int hh = dp[i1][j1 + 1][i2];
            int hv = dp[i1][j1 + 1][i2 + 1];
            int vv = dp[i1 + 1][j1][i2 + 1];
            int vh = dp[i1 + 1][j1][i2];

            cherry += max(hh, max(hv, max(vv, vh)));
            dp[i1][j1][i2] = cherry;
          }
        }
      }
    }
    return max(0, dp[0][0][0]);
  }
};