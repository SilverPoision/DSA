class Solution
{
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
  {
    vector<vector<int>> directions = {
        {0, 1},  // EAST
        {1, 0},  // SOUTH
        {0, -1}, // WEST
        {-1, 0}  // NORTH
    };

    vector<vector<int>> result;
    int step = 0; // how much steps to move
    int dir = 0;  // Which direction

    result.push_back({rStart, cStart});

    while (result.size() < rows * cols)
    {
      // When we move EAST or WEST, we need to increase our steps by 1
      if (dir == 0 || dir == 2)
        step++;

      for (int i = 0; i < step; i++)
      {
        rStart += directions[dir][0];
        cStart += directions[dir][1];

        if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) // check valid
          result.push_back({rStart, cStart});
      }

      dir = (dir + 1) % 4; // turn to next direction
    }
    return result;
  }
};

// m
class Solution
{
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c)
  {
    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, 1, 0, -1};

    vector<vector<int>> ans, mat(rows, vector<int>(cols, -1));

    int idx = 0;

    while (ans.size() < (rows * cols))
    {
      if (r >= 0 && c >= 0 && r < rows && c < cols && mat[r][c] == -1)
      {
        ans.push_back({r, c});
        mat[r][c] = 1;
      }

      int nr = r + row[(idx + 1) % 4];
      int nc = c + col[(idx + 1) % 4];
      if (nr >= rows || nc >= cols || nc < 0 || nr < 0 || mat[nr][nc] == -1)
      {
        idx = (idx + 1) % 4;
      }
      r += row[idx];
      c += col[idx];
    }

    return ans;
  }
};