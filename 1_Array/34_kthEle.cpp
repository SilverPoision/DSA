#include <bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays of size m and n respectively, you are
tasked with finding the element that would be at the k’th
position of the final sorted array Time Complexity:
O(log n + log m)

Divide And Conquer
By using a divide and conquer approach, similar to the one used in binary search, we can attempt to find the k’th element in a more efficient way.
Compare the middle elements of arrays arr1 and arr2, let us call these indices mid1 and mid2 respectively. Let us assume arr1[mid1]  k, then clearly the elements after mid2 cannot be the required element. Set the last element of arr2 to be arr2[mid2].
In this way, define a new subproblem with half the size of one of the arrays.
*/

int kthElement(vector<int> &arr1, int n, vector<int> &arr2, int m, int k)
{
  if (m < n)
    return kthElement(arr2, m, arr1, n, k);

  int low = max(0, k - m); // if k > m and we took 0 elements from first array then its impossible to complete k ele that's why we take max(0,k-m) ele.
  int high = min(n, k);    // if n > k then we can't take n ele because its is impossible as we have to take k no of elements in each sides and remaining can be pushed towards other side.

  while (low <= high)
  {
    int cut1 = (low + high) / 2; // in total we have to take k ele in one half
    int cut2 = k - cut1;

    int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
    int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
    int r1 = cut1 == n ? INT_MAX : arr1[cut1];
    int r2 = cut2 == m ? INT_MAX : arr2[cut2];

    if (l1 <= r2 && l2 <= r1)
    {
      return max(l1, l2);
    }
    else if (l1 > r2)
    {
      high = cut1 - 1; // we cut 1 ele from the first l1 array
    }
    else // l2 > r1
    {
      low = cut1 + 1; // we increase the no of ele in l1 arr so that we take one less element from the second arr so that l2 can be reduced.
    }
  }
  return -1;
}

int main()
{
  vector<int> arr1{2, 3, 6, 7, 9};
  vector<int> arr2 = {1, 4, 8, 10};

  int k = 5;
  cout << kthElement(arr1, arr1.size(), arr2, arr2.size(), k);
  return 0;
}
