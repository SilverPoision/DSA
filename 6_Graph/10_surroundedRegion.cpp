/*
130. Surrounded Regions
Medium
6.6K
1.4K
Companies
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
*/

class Solution
{
public:
  void dfs(vector<vector<char>> &mat, vector<vector<bool>> &vis, int i, int j)
  {
    vis[i][j] = true;
    vector<int> rowN = {0, 0, 1, -1};
    vector<int> colN = {1, -1, 0, 0};

    for (int ind = 0; ind < 4; ind++)
    {
      int row = i + rowN[ind];
      int col = j + colN[ind];

      if (row >= 0 && col >= 0 && row < mat.size() && col < mat[0].size() && mat[row][col] == 'O' && vis[row][col] == false)
      {
        dfs(mat, vis, row, col);
      }
    }
  }
  void solve(vector<vector<char>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
      if (vis[i][0] == false && mat[i][0] == 'O')
      {
        dfs(mat, vis, i, 0);
      }
      if (vis[i][m - 1] == false && mat[i][m - 1] == 'O')
      {
        dfs(mat, vis, i, m - 1);
      }
    }
    for (int j = 0; j < m; j++)
    {
      if (vis[0][j] == false && mat[0][j] == 'O')
      {
        dfs(mat, vis, 0, j);
      }
      if (vis[n - 1][j] == false && mat[n - 1][j] == 'O')
      {
        dfs(mat, vis, n - 1, j);
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vis[i][j] && mat[i][j] == 'O')
        {
          mat[i][j] = 'X';
        }
      }
    }
  }
};