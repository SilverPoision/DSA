#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr, int pos)
{
  int n = arr.size();
  vector<int> count(10, 0);
  vector<int> out(arr.size());

  for (int i = 0; i < n; i++)
  {
    count[((arr[i] / pos) % 10)]++;
  }

  for (int i = 1; i < n; i++)
  {
    count[i] += count[i - 1]; // to make the count arr say that this number should be till x ind in the original arr check jeenyes lecture
  }

  for (int i = n - 1; i >= 0; i--) // to preserve the stability
  {
    out[--count[(arr[i] / pos) % 10]] = arr[i]; // decrementing the ind to make it fit the 0index
  }

  for (int i = 0; i < n; i++)
  {
    arr[i] = out[i];
  }
}

void radixsort(vector<int> &arr)
{
  int max = *max_element(arr.begin(), arr.end());

  for (int pos = 1; max / pos > 0; pos *= 10)
  {
    countSort(arr, pos);
  }
}

int main()
{
  vector<int> arr = {3, 1, 4, 2, 6, 8, 4, 5, 32, 1};
  radixsort(arr);
  for (auto it : arr)
    cout << it << " ";
  return 0;
}