class Solution
{
public:
  void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &out, pair<int, int> parent)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> rowN = {0, 0, 1, -1};
    vector<int> colN = {-1, 1, 0, 0};
    vis[i][j] = true;
    out.push_back({i - parent.first, j - parent.second});

    for (int ind = 0; ind < 4; ind++)
    {
      int row = i + rowN[ind];
      int col = j + colN[ind];

      if (row >= 0 && col >= 0 && row < n && col < m && !vis[row][col] && grid[row][col] == 1)
      {
        dfs(row, col, grid, vis, out, parent);
      }
    }
  }
  int countDistinctIslands(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> s;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vis[i][j] && grid[i][j] == 1)
        {
          vector<pair<int, int>> out;
          dfs(i, j, grid, vis, out, {i, j});
          s.insert(out);
        }
      }
    }
    return s.size();
  }
};