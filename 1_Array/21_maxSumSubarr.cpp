#include <bits/stdc++.h>
using namespace std;

/*
Find the contiguous subarray within an array[] of length N
which has the largest sum in Time Complexity O(n) and Space
Complexity O(1) - Kadane Algorithm

Solution:
1. run a loop and asign intermidSum = arr[i] and then check if
intermidSum < 0 if yes the set intermidSum = 0,
check if the intermidSum < arr[i] if yer then intermidSum = arr[i]
check if intermidSum > resultSum then resultSum = intermidSum;
*/

int kadane(vector<int> &arr)
{
  int res = -1e9;
  int sum = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    sum += arr[i];
    res = max(res, sum);
    if (sum < 0)
      sum = 0;
  }

  return res;
}

int main()
{
  vector<int> arr = {1, 2, 7, -4, 3, 2, -10, 9, 1};

  cout << "The sum of contiguous sub-array with the largest sum is " << kadane(arr);

  return 0;
}

/* Try more Inputs

case1:
actual = maxSubArraySum([-2,1,-3,4,-1,2,1,-5,4],9)
expected = 6

case2:
actual = maxSubArraySum([1],1)
expected = 1

case3:
actual = maxSubArraySum([-4, 2, -5, 1, 2, 3, 6, -5, 1],9)
expected = 12

case4:
actual = maxSubArraySum([-5, 6, -7, 1, 4, -8, 16],7)
expected = 16

*/