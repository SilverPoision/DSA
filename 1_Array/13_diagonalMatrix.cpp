#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Given a matrix of M x N elements (M rows, N columns),
Print all elements of the matrix in diagonal order in
Time Complexity O(m*n) and Space Complexity O(1)
*/

class Solution
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat)
  {
    int n = mat[0].size();
    int m = mat.size();
    int row = 0, col = 0;
    bool up = true;
    vector<int> arr;

    while (row < m && col < n)
    {
      if (up)
      {
        while (row > 0 && col < n - 1)
        {
          arr.push_back(mat[row][col]);
          row--;
          col++;
        }
        arr.push_back(mat[row][col]);
        if (col == n - 1)
        {
          row++;
        }
        else
        {
          col++;
        }
      }
      else
      {
        while (col > 0 && row < m - 1)
        {
          arr.push_back(mat[row][col]);
          col--;
          row++;
        }
        arr.push_back(mat[row][col]);
        if (row == m - 1)
        {
          col++;
        }
        else
        {
          row++;
        }
      }
      up = !up;
    }
    return arr;
  }
};