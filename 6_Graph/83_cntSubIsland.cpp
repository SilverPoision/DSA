class Solution
{
public:
  // DFS
  bool checkSubIsland(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
  {
    if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size())
    {
      return true;
    }

    if (grid2[i][j] != 1)
    { // we only need land
      return true;
    }

    grid2[i][j] = -1; // mark visited

    bool result = (grid1[i][j] == 1); // grid1[i][j] must have 1

    result = result & checkSubIsland(grid1, grid2, i + 1, j); // Down
    result = result & checkSubIsland(grid1, grid2, i - 1, j); // Up
    result = result & checkSubIsland(grid1, grid2, i, j + 1); // Right
    result = result & checkSubIsland(grid1, grid2, i, j - 1); // Left

    return result;
  }

  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
  {
    // DFS
    int subIslands = 0;
    int m = grid2.size();    // rows
    int n = grid2[0].size(); // cols

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j))
        { // Found an island
          subIslands++;
        }
      }
    }

    return subIslands;
  }
};

// kkk
class Solution
{
public:
  vector<int> col = {1, -1, 0, 0};
  vector<int> row = {0, 0, -1, 1};
  bool dfs(int i, int j, vector<vector<int>> &grid1,
           vector<vector<int>> &grid2, vector<vector<int>> &vis)
  {
    grid2[i][j] = 0;
    grid1[i][j] = 0;
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
      int r = i + row[k];
      int c = j + col[k];

      if (r >= 0 && r < grid1.size() && c >= 0 && c < grid1[0].size() &&
          grid1[r][c] == 1 && grid2[r][c] == 1)
        if (!dfs(r, c, grid1, grid2, vis))
        {
          grid2[i][j] = 1;
          grid1[i][j] = 1;
          return false;
        }

      if (r >= 0 && r < grid1.size() && c >= 0 && c < grid1[0].size() &&
          grid2[r][c] == 1 && grid1[r][c] != 1)
      {
        grid2[i][j] = 1;
        grid1[i][j] = 1;
        return false;
      }
    }

    grid2[i][j] = 1;
    grid1[i][j] = 1;

    return true;
  }
  int countSubIslands(vector<vector<int>> &grid1,
                      vector<vector<int>> &grid2)
  {
    int n = grid1.size();
    int m = grid1[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid2[i][j] == 1 && grid1[i][j] == 1 && vis[i][j] != 1)
        {
          bool res = dfs(i, j, grid1, grid2, vis);
          if (res)
            cnt++;
        }
      }
    }

    return cnt;
  }
};