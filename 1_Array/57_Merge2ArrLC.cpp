/*
88. Merge Sorted Array
Easy
10.7K
1.1K
Companies
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    if (m == 0)
    {
      nums1 = nums2;
      return;
    }

    int i = m - 1, j = n - 1;
    int size = nums1.size() - 1;

    while (i >= 0 && j >= 0)
    {
      if (nums1[i] >= nums2[j])
      {
        nums1[size--] = nums1[i];
        i--;
      }
      else
      {
        nums1[size--] = nums2[j];
        j--;
      }
    }

    while (j >= 0)
    {
      nums1[size--] = nums2[j--];
    }
  }
};

/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Example 1:

Input:
n = 4, arr1[] = [1 3 5 7]
m = 5, arr2[] = [0 2 6 8 9]
Output:
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two
non-decreasing arrays, we get,
0 1 2 3 5 6 7 8 9.
*/

class Solution
{
public:
  // Function to merge the arrays.
  void merge(long long arr1[], long long arr2[], int n, int m)
  {
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
      if (arr1[left] > arr2[right])
      {
        swap(arr1[left], arr2[right]);
        left--;
        right++;
      }
      else
      {
        break;
      }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
  }
};