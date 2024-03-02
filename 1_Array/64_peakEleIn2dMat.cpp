/*
The algorithm is as follows:

Pick the middle column.
Find the global maximum in the column.
If the row-neighbours of this element are smaller, then we found a 2D peak. Else, we recurse at the right-half of the matrix if the right-neighbour was bigger, and left-half of the matrix if the left-neighbour was bigger.
Here is a little intuition as to why this works.

When we find a row-neighbour that is bigger than the global maximum of a column, it means that the row-neighbour is bigger than all the elements of that column. Thus, the global maximum of the neighbour's column must be bigger than its corresponding row-neighbour in our column.
*/

class Solution
{
public:
  vector<int> findPeakGrid(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      int maxRow = 0;
      for (int i = 0; i < n; i++)
      {
        if (mat[maxRow][mid] < mat[i][mid])
        {
          maxRow = i;
        }
      }

      if ((mid == 0 || mat[maxRow][mid] > mat[maxRow][mid - 1]) && (mid == m - 1 || mat[maxRow][mid] > mat[maxRow][mid + 1]))
      {
        return {maxRow, mid};
      }
      else if (mid > 0 && mat[maxRow][mid] < mat[maxRow][mid - 1])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return {-1, -1};
  }
};