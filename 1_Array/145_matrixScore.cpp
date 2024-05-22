class Solution
{
public:
  // https://www.youtube.com/watch?v=1c5HnSKNABA
  int matrixScore(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;
    ans += n * (1 << (m - 1));

    for (int j = 1; j < m; j++)
    {
      int cnt = 0;
      for (int i = 0; i < n; i++)
      {
        cnt += grid[i][0] == 0 ? grid[i][j] ^ 1 : grid[i][j];
      }
      if ((n - cnt) > cnt)
      {
        ans += (n - cnt) * (1 << m - 1 - j);
      }
      else
      {
        ans += cnt * (1 << m - 1 - j);
      }
    }

    return ans;
  }
};

class Solution
{
public:
  // https://leetcode.com/problems/score-after-flipping-matrix/?envType=daily-question&envId=2024-05-13
  int matrixScore(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
      if (grid[i][0] == 0)
      {
        for (int j = 0; j < m; j++)
          grid[i][j] = grid[i][j] == 1 ? 0 : 1;
      }
    }

    for (int j = 0; j < m; j++)
    {
      int cnt = 0;
      for (int i = 0; i < n; i++)
      {
        cnt += grid[i][j];
      }
      if ((n - cnt) > cnt)
      {
        for (int i = 0; i < n; i++)
        {
          grid[i][j] = grid[i][j] == 1 ? 0 : 1;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int bin = 0;
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          bin |= (1 << m - j - 1);
        }
      }
      ans += bin;
    }

    return ans;
  }
};