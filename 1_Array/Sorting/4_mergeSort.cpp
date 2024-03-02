#include <bits/stdc++.h>
using namespace std;

void merge(int low, int high, int mid, vector<int> &arr, vector<int> &res)
{
  int i = low, j = mid + 1, k = low;
  while (i <= mid && j <= high)
  {
    if (arr[i] >= arr[j])
    {
      res[k++] = arr[j++];
    }
    else
    {
      res[k++] = arr[i++];
    }
  }

  while (i <= mid)
  {
    res[k++] = arr[i++];
  }
  while (j <= high)
  {
    res[k++] = arr[j++];
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = res[i];
  }
}

void mergesort(vector<int> &arr, int low, int high, vector<int> &res)
{
  if (high == low)
    return;
  int mid = ((low + high) / 2);
  mergesort(arr, low, mid, res);
  mergesort(arr, mid + 1, high, res);
  merge(low, high, mid, arr, res);
}

int main()
{
  vector<int> arr = {3, 1, 4, 2, 6, 8, 4, 5, 32, 1};
  vector<int> res(arr.size());
  mergesort(arr, 0, arr.size(), res);
  for (auto it : arr)
    cout << it << " ";
  return 0;
}