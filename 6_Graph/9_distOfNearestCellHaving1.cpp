/*
Distance of nearest cell having 1
MediumAccuracy: 47.7%Submissions: 46K+Points: 4

Given a binary grid of n*m. Find the distance of the nearest 1 in the
grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1
are the row number and column number of the current cell,
and i2, j2 are the row number and column number of the nearest
cell having value 1.


Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0
1 1 0 0
0 0 1 1
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
*/

class Solution
{
public:
  // Function to find distance of nearest 1 in the grid for each cell.
  vector<vector<int>> nearest(vector<vector<int>> grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<int> rowN = {0, 0, 1, -1};
    vector<int> colN = {1, -1, 0, 0};

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          q.push({{i, j}, 0});
          vis[i][j] = true;
          mat[i][j] = 0;
        }
      }
    }

    while (!q.empty())
    {
      int rowI = q.front().first.first;
      int colI = q.front().first.second;
      int dist = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int row = rowI + rowN[i];
        int col = colI + colN[i];

        if (row >= 0 && col >= 0 && row < n && col < m && grid[row][col] != 1 && vis[row][col] == false)
        {
          vis[row][col] = true;
          mat[row][col] = dist + 1;
          q.push({{row, col}, dist + 1});
        }
      }
    }
    return mat;
  }
};

// Why dfs doesnt work?