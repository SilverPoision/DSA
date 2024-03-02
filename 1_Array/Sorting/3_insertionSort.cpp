#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
  for (int i = 1; i < n; i++)
  {
    int ind = i;

    while (ind > 0 && arr[ind - 1] > arr[ind])
    {
      swap(arr[ind - 1], arr[ind]);
      ind--;
    }
  }
}

int main()
{
  vector<int> arr = {3, 1, 4, 2, 6, 8, 4, 5, 32, 1};
  insertionSort(arr);
  for (auto it : arr)
    cout << it << " ";
  return 0;
}