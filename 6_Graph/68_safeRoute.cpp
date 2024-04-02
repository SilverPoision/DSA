class Solution
{
public:
  vector<int> row = {0, 1, 0, -1};
  vector<int> col = {1, 0, -1, 0};
  int mini;

  void dfs(int i, int j, vector<vector<int>> &mat, int n, int m, int step, vector<vector<int>> vis)
  {
    if (j == m - 1)
    {
      mini = min(mini, step);
      return;
    }
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
      int r = i + row[k];
      int c = j + col[k];

      if (r < n && r >= 0 && c < m && c >= 0 && mat[r][c] == 1 && !vis[r][c])
      {
        dfs(r, c, mat, n, m, step + 1, vis);
      }
    }
    vis[i][j] = 0;
  }
  int findShortestPath(vector<vector<int>> &mat)
  {
    // code here
    int n = mat.size();
    int m = mat[0].size();

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mat[i][j] == 0)
          st.push({i, j});
      }
    }

    while (!st.empty())
    {
      auto k = st.top();
      int i = k.first;
      int j = k.second;
      st.pop();

      for (int k = 0; k < 4; k++)
      {
        int r = i + row[k];
        int c = j + col[k];

        if (r < n && r >= 0 && c < m && c >= 0 && mat[r][c] == 1)
        {
          mat[r][c] = 0;
        }
      }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    mini = 1e9;
    for (int i = 0; i < n; i++)
    {
      if (mat[i][0] == 1)
        dfs(i, 0, mat, n, m, 1, vis);
    }

    return mini == 1e9 ? -1 : mini;
  }
};