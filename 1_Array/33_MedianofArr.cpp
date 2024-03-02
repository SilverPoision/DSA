#include <bits/stdc++.h>
using namespace std;

/*
Binary search method to find Median of two sorted Array

Solution :
Think of a binary search algo where you pick equal no of ele
From both the arrs because we have to find the correct partition
That will give us the correct left and right partitions.
Then we will take the median according to the rules of odds and evens
*/
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n2 < n1)
    {
      return findMedianSortedArrays(nums2, nums1);
    }

    int low = 0, high = n1;

    while (low <= high)
    {
      int cut1 = (low + high) / 2;
      int cut2 = (n1 + n2 + 1) / 2 - cut1;

      int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
      int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
      int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
      int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

      if (l1 <= r2 && l2 <= r1)
      {
        if ((n1 + n2) % 2 == 0)
        {
          return ((max(l1, l2) + min(r1, r2)) / 2.0);
        }
        else
        {
          return max(l1, l2);
        }
      }
      else
      {
        if (l1 > r2)
        {
          high = cut1 - 1;
        }
        else
        {
          low = cut1 + 1;
        }
      }
    }

    return 0.0;
  }
};

/* Try more Inputs

case1:
 actual = getMedian([0,0],[0,0],2)
 expected = 0

case2:
actual = getMedian([2,7],[11,16],2)
expected = 9

case3:
actual = getMedian([1,2,3,6],[4,6,8,10],4)
expected = 5
*/
