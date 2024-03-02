#include <iostream>
using namespace std;

// You have an array of non-negative integers,you are initially
// positioned at the first index of the array.Each element in
// the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index in O(n)
// Time complexity and O(1) Space Complexity Asked in :

/*
Solution:
1. Take 3 ints a b and jump and put the value of arr[0]
in and b and jump =1
2. decrement a and b on every step forward
3. if a[i] > b then b = a[i] and if a = 0; a = b and jump++;
*/

bool canJump(vector<int> &nums)
{
  int goal = nums.size() - 1;

  for (int i = nums.size() - 1; i >= 0; i--)
  {
    if (i + nums[i] >= goal)
      goal = i;
  }

  return goal == 0;
}

int main()
{
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int jump = canJump(arr, n);
  cout << jump << endl;
  return 0;
}

// DP
bool f(vector<int> &nums, int i, vector<int> &dp)
{
  if (i == nums.size() - 1)
    return true;
  if (i >= nums.size())
    return false;

  if (dp[i] != -1)
    return dp[i];

  for (int k = 1; k <= nums[i]; k++)
  {
    if (f(nums, i + k, dp))
      return dp[i] = true;
  }

  return dp[i] = false;
}
bool canJump(vector<int> &nums)
{
  vector<int> dp(nums.size(), -1);
  return f(nums, 0, dp);
}