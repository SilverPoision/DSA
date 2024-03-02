#include <iostream>
using namespace std;

/*
you are given a matrix of m x n elements (m rows, n columns),
Print all elements of the matrix in spiral order in O(m*n)
Time Complexity and O(1) Space Complexity Asked in: Microsoft,
OLA, PayTm, Oracle

Solution:
*/

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    int top = 0, left = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
    vector<int> ans;
    while (top <= bottom && left <= right)
    {
      for (int i = left; i <= right; i++)
      {
        ans.push_back(matrix[top][i]);
      }
      top++;
      for (int i = top; i <= bottom; i++)
      {
        ans.push_back(matrix[i][right]);
      }
      right--;

      if (!(left <= right && top <= bottom))
      {
        break;
      }

      for (int i = right; i >= left; i--)
      {
        ans.push_back(matrix[bottom][i]);
      }
      bottom--;
      for (int i = bottom; i >= top; i--)
      {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
    return ans;
  }
};

/* Try more Inputs
case 1:
actual = spiralPrint(3,3,[[1,2,3],[4,5,6],[7,8,9]])
expected = [[1,2,3,6,9,8,7,4,5]]

case2:
 actual = spiralPrint(3,4,[[1,2,3,4],[5,6,7,8],[9,10,11,12]])
 expected = [1,2,3,4,8,12,11,10,9,5,6,7]

*/