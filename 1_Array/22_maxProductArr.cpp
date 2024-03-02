/*
152. Maximum Product Subarray
Medium
14.8K
440
Companies
Given an integer array nums, find a
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/

#include <vector>

int subarrayWithMaxProduct(vector<int> &arr)
{
  int n = arr.size();
  int prefix = 1, suffix = 1, maxi = -1e9;
  for (int i = 0; i < n; i++)
  {
    if (prefix == 0)
      prefix = 1;
    if (suffix == 0)
      suffix = 1;
    prefix *= arr[i];
    suffix *= arr[n - i - 1];

    maxi = max(maxi, max(prefix, suffix));
  }

  return maxi;
}

// Kadane
class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int res = -1e9;
    for (auto it : nums)
      res = max(res, it);
    int n = nums.size();
    int currMin = 1, currMax = 1;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
      {
        currMin = 1, currMax = 1;
        continue;
      }
      int temp = currMax * nums[i];
      currMax = max(max(currMax * nums[i], currMin * nums[i]), nums[i]);
      currMin = min(min(temp, currMin * nums[i]), nums[i]);
      res = max(res, currMax);
    }

    return res;
  }
};