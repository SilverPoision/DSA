#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
  int *temp = a;
  a = b;
  b = temp;
}

void selectSort(vector<int> &arr)
{
  for (int i = 0; i < arr.size() - 1; i++)
  {
    int mini = i;
    for (int j = i + 1; j < arr.size(); j++)
    {
      if (arr[j] < arr[mini])
      {
        mini = j;
      }
    }
    swap(arr[i], arr[mini]);
  }
}

int main()
{
  vector<int> arr = {3, 1, 4, 2, 6, 8, 4, 5, 32, 1};
  selectSort(arr);
  for (auto it : arr)
    cout << it << " ";
  return 0;
}