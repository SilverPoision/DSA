/*
1020. Number of Enclaves
Medium
2.2K
40
Companies
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
*/

class Solution
{
public:
  void dfs(vector<vector<int>> &mat, vector<vector<int>> &vis, int i, int j)
  {
    cout << i << " " << j;
    vis[i][j] = 2;
    vector<int> rowN = {0, 0, 1, -1};
    vector<int> colN = {1, -1, 0, 0};

    for (int ind = 0; ind < 4; ind++)
    {
      int row = i + rowN[ind];
      int col = j + colN[ind];

      if (row >= 0 && col >= 0 && row < mat.size() && col < mat[0].size() && vis[row][col] == 1)
      {
        dfs(mat, vis, row, col);
      }
    }
  }
  int numEnclaves(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis = mat;
    for (int i = 0; i < n; i++)
    {
      if (vis[i][0] == 1)
      {
        dfs(mat, vis, i, 0);
      }
      if (vis[i][m - 1] == 1)
      {
        dfs(mat, vis, i, m - 1);
      }
    }
    for (int j = 0; j < m; j++)
    {
      if (vis[0][j] == 1)
      {
        dfs(mat, vis, 0, j);
      }
      if (vis[n - 1][j] == 1)
      {
        dfs(mat, vis, n - 1, j);
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (vis[i][j] == 1)
        {
          cnt++;
        }
      }
    }
    return cnt;
  }
};