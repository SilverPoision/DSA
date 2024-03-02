class Solution
{
public:
  int n, m, time = 1;
  vector<pair<int, int>> steps = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  void dfs(int i, int j, int iP, int jP,
           map<pair<int, int>, pair<int, int>> &parent,
           map<pair<int, int>, bool> &vis, map<pair<int, int>, int> &low,
           map<pair<int, int>, int> &tin, vector<vector<int>> &grid,
           bool &flag)
  {

    vis[{i, j}] = true;
    parent[{i, j}] = {iP, jP};
    tin[{i, j}] = low[{i, j}] = time++;
    int child = 0;

    for (auto st : steps)
    {
      int r = i + st.first;
      int c = j + st.second;

      if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1)
      {
        if (!vis[{r, c}])
        {
          child++;
          dfs(r, c, i, j, parent, vis, low, tin, grid, flag);
          low[{i, j}] = min(low[{i, j}], low[{r, c}]);
          if (low[{r, c}] >= tin[{i, j}] &&
              parent[{i, j}] != make_pair(-1, -1))
          {
            flag = true;
          }
        }
        else
        {
          low[{i, j}] = min(low[{i, j}], tin[{r, c}]);
        }
      }
    }

    if (parent[{i, j}] == make_pair(-1, -1) && child > 1)
      flag = true;
  }

  int minDays(vector<vector<int>> &grid)
  {
    n = grid.size();
    m = grid[0].size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j])
          sum++;
      }
    }

    if (sum == 1)
      return 1;
    else if (sum == 0)
      return 0;
    else if (sum == n * m)
      return 2;

    map<pair<int, int>, bool> vis;
    map<pair<int, int>, int> low, tin;
    map<pair<int, int>, pair<int, int>> parent;
    int cnt = 0;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1 && !vis[{i, j}])
        {
          cnt++;
          if (cnt > 1)
            return 0;
          dfs(i, j, -1, -1, parent, vis, low, tin, grid, flag);
        }
      }
    }

    if (flag)
      return 1;

    return 2;
  }
};

class Solution
{
public:
  vector<int> r = {0, 0, 1, -1};
  vector<int> c = {1, -1, 0, 0};
  int n, m;

  int countIsland(vector<vector<int>> &grid)
  {
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1 && !vis[i][j])
        {
          cnt++;
          dfs(i, j, grid, vis);
        }
      }
    }
    return cnt;
  }
  void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis)
  {
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
      int row = i + r[k];
      int col = j + c[k];

      if (row < n && col < m && row >= 0 && col >= 0 && !vis[row][col] &&
          grid[row][col] == 1)
      {
        dfs(row, col, grid, vis);
      }
    }
  }
  int minDays(vector<vector<int>> &grid)
  {
    n = grid.size();
    m = grid[0].size();

    vector<vector<int>> temp = grid;

    int comp = countIsland(grid);
    if (comp != 1)
    {
      return 0;
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (temp[i][j] == 1)
        {
          temp[i][j] = 0;
          int comp = countIsland(temp);
          if (comp != 1)
            return 1;
          temp[i][j] = 1;
        }
      }
    }

    return 2;
  }
};