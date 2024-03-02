#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(vector<int> &arr)
{
  for (int i = 0; i < arr.size() - 1; i++)
  {
    bool swaps = false;
    for (int j = 0; j < arr.size() - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swaps = true;
        swap(&arr[j], &arr[j + 1]);
      }
    }
    if (!swaps)
      break;
  }
}

int main()
{
  vector<int> arr = {3, 1, 4, 2, 6, 8, 4, 5, 32, 1};
  bubbleSort(arr);
  for (auto it : arr)
    cout << it << " ";
  return 0;
}