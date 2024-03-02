#include <bits/stdc++.h>
using namespace std;

/*
Matrix n*n is given, where all elements in any individual row or
column are sorted. In such a matrix, we have to find the
position of a value in O(n) Time Complexity and O(1) Space
Complexity

Solution:
1. check if mat[i][j] == key if yes return if not
2. then check if (mat[i][j] > key) then j-- or i++;
*/

#define n 4

bool search(int mat[n][n], int key)
{
  int i = 0, j = n - 1;
  while (i < n && j >= 0)
  {
    if (mat[i][j] == key)
    {
      return true;
    }
    if (mat[i][j] > key)
    {
      j--;
    }
    else
    {
      i++;
    }
  }
}

int main()
{

  int mat[n][n] = {{10, 20, 30, 40},
                   {15, 25, 35, 45},
                   {27, 29, 37, 48},
                   {32, 33, 39, 50}};
  bool x = search(mat, 36);

  cout << x << endl;

  return 0;
}

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &mat, int target)
  {
    if (mat.empty())
      return false;
    int n = mat.size();
    int m = mat[0].size();

    if (mat[0][0] > target || mat[n - 1][m - 1] < target)
      return false;

    int top = 0, bot = n - 1, row;

    while (top <= bot)
    {
      row = (top + bot) / 2;
      if (target > mat[row][m - 1])
      {
        top = row + 1;
      }
      else if (target < mat[row][0])
      {
        bot = row - 1;
      }
      else if (target == mat[row][0])
      {
        return true;
      }
      else
      {
        break;
      }
    }

    int left = 0, right = m - 1, mid;

    while (left <= right)
    {
      mid = (left + right) / 2;
      if (target == mat[row][mid])
        return true;
      if (target > mat[row][mid])
        left = mid + 1;
      else if (target < mat[row][mid])
        right = mid - 1;
    }

    return false;
  }
};