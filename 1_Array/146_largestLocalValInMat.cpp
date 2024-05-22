class Solution
{
public:
  // https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12
  vector<vector<int>> largestLocal(vector<vector<int>> &grid)
  {
    int n = grid.size();

    vector<vector<int>> ans(n - 3 + 1, vector<int>(n - 3 + 1, 0));

    for (int i = 0; i + 3 <= n; i++)
    {
      for (int j = 0; j + 3 <= n; j++)
      {
        int maxi = 0;
        for (int k = i; k < i + 3; k++)
        {
          for (int l = j; l < j + 3; l++)
          {
            maxi = max(maxi, grid[k][l]);
          }
        }
        ans[i][j] = maxi;
      }
    }

    return ans;
  }
};