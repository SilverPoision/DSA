class Solution
{
public:
  // https://leetcode.com/problems/lucky-numbers-in-a-matrix/?envType=daily-question&envId=2024-07-19
  vector<int> luckyNumbers(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> col(m, -1e9), row(n, 1e9);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        row[i] = min(row[i], mat[i][j]);
        col[j] = max(col[j], mat[i][j]);
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (row[i] == col[j])
          ans.push_back(row[i]);
      }
    }

    return ans;
  }
};