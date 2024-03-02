/*
189. Rotate Array
Medium
12.6K
1.5K
Companies
Given an array, rotate the array to the right by k steps, where k is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    for (int j = 0; j < k; j++)
    {
      int temp = nums[n - 1];
      for (int i = n - 1; i >= 0; i--)
      {
        if (i == 0)
        {
          nums[i] = temp;
          break;
        }
        nums[i] = nums[i - 1];
      }
    }

    for (auto it : nums)
    {
      cout << it << " ";
    }
  }
};

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    k = k % nums.size();
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());

    for (auto it : nums)
    {
      cout << it << " ";
    }
  }
};