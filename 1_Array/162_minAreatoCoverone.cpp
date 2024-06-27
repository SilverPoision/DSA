class Solution
{
public:
  // https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
  int minimumArea(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    int f = 1e9, last = -1, up = 1e9, bottom = -1;

    for (int j = 0; j < n; j++)
    {
      for (int i = 0; i < m; i++)
      {
        if (grid[j][i] == 1)
        {
          f = min(f, i);
          last = max(i, last);
          up = min(up, j);
          bottom = max(bottom, j);
        }
      }
    }

    int len = last - f + 1;
    int b = bottom - up + 1;

    return len * b;
  }
};