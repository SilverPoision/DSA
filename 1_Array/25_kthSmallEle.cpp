#include <bits/stdc++.h>
using namespace std;

/*
Find kth smallest element in that in an unsorted integer array
in Time Complexity O(n) and Space Complexity O(1) Asked in :
Vmware, SapLabs, WalmartLabs

Solution:
In QuickSort, we pick a pivot element, then move the pivot
element to its correct position and partition the surrounding
array. The idea is, not to do complete quicksort, but stop at
the point where pivot itself is k’th smallest element. Also,
not to recur for both left and right sides of pivot, but recur f
or one of them according to the position of pivot. The worst
case time complexity of this method is O(n2), but it works in O(n) on average.
*/

int findKthSmallest(vector<int> &arr, int l, int r, int k)
{
  int pivot = arr[r];
  int pIndex = l;

  for (int i = l; i < r; i++)
  {
    if (arr[i] <= pivot)
    {
      swap(arr[i], arr[pIndex++]);
    }
  }
  swap(arr[pIndex], arr[r]);

  int countOfElements = pIndex - l + 1;
  if (k < countOfElements)
  {
    return findKthSmallest(arr, l, pIndex - 1, k);
  }
  else if (k > countOfElements)
  {
    return findKthSmallest(arr, pIndex + 1, r, k - countOfElements);
  }
  else
  {
    return arr[pIndex];
  }
}

int main()
{
  vector<int> arr = {7, 10, 4, 3, 20, 15};
  int k = 3;
  cout << "K'th smallest element is " << findKthSmallest(arr, 0, arr.size() - 1, k);
  return 0;
}

/* Try more Inputs
case 1:
actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,3)
expected = 7

case2:
 actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,4)
 expected = 10

case3:
actual = findKthElement([12, 3, 5, 7, 19],0,4,2)
expected = 5
*/