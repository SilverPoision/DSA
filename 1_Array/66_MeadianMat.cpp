// https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix/

class Solution
{
public:
  int countLesserThanEqualTo(vector<int> &arr, int x)
  {
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (arr[mid] <= x)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return low;
  }
  int median(vector<vector<int>> &matrix, int R, int C)
  {
    int low = 0, high = 1e9, d = (C * R) / 2;

    while (low <= high)
    {
      int mid = (low + high) >> 1;
      int cnt = 0;

      for (int i = 0; i < R; i++)
      {
        cnt += countLesserThanEqualTo(matrix[i], mid);
      }

      if (d >= cnt)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return low;
  }
};