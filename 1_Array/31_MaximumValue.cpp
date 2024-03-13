#include <bits/stdc++.h>
using namespace std;

/*
Given an array A[] of N positive integers. The task is to find
the maximum of j - i with the constraint of A[i] <= A[j]. Time
Complexity : O(n) Space Complexity : O(n)

Solution:

Make a right array and fill all the values that are greater in right
and then comoare arr[i] to right[j] with i =0 and j = n-1 and make
a maxdiff array and check of its bigger or not then overwrite its value.
*/

class Solution
{
public:
  // A[]: input array
  // N: size of array
  // Function to find the maximum index difference.
  int maxIndexDiff(int arr[], int n)
  {
    // Your code here
    vector<int> left(n), right(n);
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
      left[i] = min(arr[i], left[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
      right[i] = max(arr[i], right[i + 1]);
    }

    int i = 0, j = 0, ans = 0;

    while (i < n && j < n)
    {
      if (left[i] <= right[j])
      {
        ans = max(ans, j - i);
        j++;
      }
      else
      {
        i++;
      }
    }

    return ans;
  }
};
/* Try more Inputs
case1:
actual = findDiff([35, 9, 12, 3, 2, 70, 31, 33, 1])
expected = 6

case2:
actual = findDiff([1, 2, 3, 4, 5, 6])
expected = 5

case3:
actual = findDiff([9, 2, 3, 4, 5, 6, 7, 8, 18, 0])
expected = 8

case4:
actual = findDiff([6, 5, 4, 3, 2, 1])
expected = -1

*/