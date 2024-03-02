class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> col(n, 1), row(m, 1);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 0)
        {
          col[i] = 0;
          row[j] = 0;
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (col[i] == 0 || row[j] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

// Optimal
// https://takeuforward.org/data-structure/set-matrix-zero/
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int n = matrix.size(), m = matrix[0].size();
    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0;

          if (j != 0)
          {
            matrix[0][j] = 0;
          }
          else
          {
            col0 = 0;
          }
        }
      }
    }

    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }

    if (matrix[0][0] == 0)
    {
      for (int i = 0; i < m; i++)
      {
        matrix[0][i] = 0;
      }
    }

    if (col0 == 0)
    {
      for (int i = 0; i < n; i++)
      {
        matrix[i][0] = 0;
      }
    }
  }
};