class Solution
{
public:
  // https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/?envType=daily-question&envId=2024-07-20
  vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
  {
    int n = rowSum.size();
    int m = colSum.size();
    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int x = min(rowSum[i], colSum[j]);
        mat[i][j] = x;
        rowSum[i] = max(0, rowSum[i] - x);
        colSum[j] = max(0, colSum[j] - x);
      }
    }

    return mat;
  }
};