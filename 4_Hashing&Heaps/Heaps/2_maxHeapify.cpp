#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int index)
{
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  int maxi = index;
  if (left <= arr.size() && arr[index] < arr[left])
  {
    maxi = left;
  }
  if (right <= arr.size() && arr[index] < arr[right])
  {
    maxi = right;
  }

  if (index != maxi)
  {
    swap(arr[index], arr[maxi]);
    heapify(arr, maxi);
  }
}

int main()
{
  vector<int> max = {2, 3, 4};
  heapify(max, 0);
  for (auto it : max)
  {
    cout << it << " ";
  }
  return 0;
}