#include <iostream>
using namespace std;

/*
A 2-D array of 1's and 0's is given. Find the row with max 1's
in Time Complexity O(nlogn) and Space Complexity O(1) .
The array is sorted row wise (all 0's in a row are followed by
all 1's.

Solution :
apply binary search and just find the index and sub with M.
*/

class Solution
{
public:
  int findMax(vector<int> arr)
  {
    int low = 0, high = arr.size() - 1;

    if (arr[0] == 1)
      return arr.size();

    while (low <= high)
    {
      int mid = (high + low) / 2;

      if (arr[mid] == 1 && arr[mid - 1] == 0)
      {
        return (arr.size() - mid);
      }
      else if (arr[mid] == 1 && arr[mid - 1] == 1)
      {
        high = mid - 1;
      }
      else if (arr[mid] == 0)
      {
        low = mid + 1;
      }
    }

    return 0;
  }

  int rowWithMax1s(vector<vector<int>> arr, int n, int m)
  {
    int maxi = 0;
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
      int lMax = findMax(arr[i]);
      if (maxi < lMax)
      {
        maxi = lMax;
        ind = i;
      }
    }

    return ind;
  }
};