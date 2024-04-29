class Solution
{
public:
  // https://leetcode.com/problems/maximum-sum-of-an-hourglass/
  //  int calc(int i, int j, vector<vector<int>> &grid)
  //  {
  //    int sum = 0;
  //    // cout << i << " " << j << endl;
  //    for (int k = 0; k < 3; k++)
  //    {
  //      sum += grid[i][j + k];
  //      sum += grid[i + 2][j + k];
  //    }

  //   return sum + grid[i + 1][j + 1];
  // }
  int maxSum(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    int maxi = -1e9;

    for (int i = 0; i + 2 < n; i++)
    {
      for (int j = 0; j + 2 < m; j++)
      {
        int sum = 0;
        for (int k = 0; k < 3; k++)
        {
          sum += grid[i][j + k];
          sum += grid[i + 2][j + k];
        }

        maxi = max(maxi, sum + grid[i + 1][j + 1]);
      }
    }

    return maxi;
  }
};