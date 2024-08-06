class Solution
{
public:
  // we are trying to find any middle node between a b like a to c1 and c1 to b
  // so that the dist of a to b is greater thean dist with middle node so k is the middle node and we are trying
  // all the middle node with all the edges
  void shortest_distance(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == -1)
          matrix[i][j] = 1e9;
        if (i == j)
          matrix[i][j] = 0;
      }
    }

    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (matrix[i][i] < 0) // this means there is a neagtive cycle present
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 1e9)
          matrix[i][j] = -1;
      }
    }
  }
};