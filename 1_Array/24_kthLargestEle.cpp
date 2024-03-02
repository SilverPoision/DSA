/*
215. Kth Largest Element in an Array
Medium
12.9K
645
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.



Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/

class Solution
{
public:
  int sort(vector<int> &num, int low, int high, int k)
  {
    if (low == high)
      return num[low];
    int pIndex = low;
    int pivot = num[high];
    for (int i = low; i < high; i++)
    {
      if (num[i] <= pivot)
      {
        swap(num[i], num[pIndex]);
        pIndex++;
      }
    }
    swap(num[high], num[pIndex]);
    if (k > pIndex)
    {
      return sort(num, pIndex + 1, high, k);
    }
    else if (k < pIndex)
    {
      return sort(num, low, pIndex - 1, k);
    }
    else
    {
      return num[pIndex];
    }
  }

  int findKthLargest(vector<int> &nums, int k)
  {
    k = nums.size() - k; // we have to look for the index of the largest ele.
    return sort(nums, 0, nums.size() - 1, k);
  }
};