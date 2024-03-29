class Solution
{
public:
  // https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
  // https://www.youtube.com/watch?v=-SWrz90jCUM&t=0s
  int numSubmatrixSumTarget(vector<vector<int>> &mat, int target)
  {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        mat[i][j] += mat[i][j - 1];
      }
    }

    int cnt = 0;
    for (int stCol = 0; stCol < m; stCol++)
    {

      for (int col = stCol; col < m; col++)
      {

        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;

        for (int row = 0; row < n; row++)
        {

          sum +=
              mat[row][col] - (stCol > 0 ? mat[row][stCol - 1] : 0);

          if (hash.count(sum - target))
          {
            cnt += hash[sum - target];
          }

          hash[sum]++;
        }
      }
    }

    return cnt;
  }
};