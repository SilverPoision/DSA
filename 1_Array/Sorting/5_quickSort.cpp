#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
  int pIndex = start;
  int piviot = arr[end];
  for (int i = start; i < end; i++)
  {
    if (arr[i] <= piviot)
    {
      swap(arr[i], arr[pIndex]);
      pIndex++;
    }
  }

  swap(arr[pIndex], arr[end]);
  return pIndex;
}

void quickSort(vector<int> &arr, int start, int end)
{
  if (start < end)
  {
    int pIndex = partition(arr, start, end);
    quickSort(arr, start, pIndex - 1);
    quickSort(arr, pIndex + 1, end);
  }
  return;
}

int main()
{
  vector<int> arr = {3, 1, 4, 2, 6, 8, 4, 5, 32, 1};
  quickSort(arr, 0, arr.size() - 1);
  for (auto it : arr)
    cout << it << " ";
  return 0;
}