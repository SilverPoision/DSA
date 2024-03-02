#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int index)
{
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  int largest = index;

  if (index < arr.size() && arr[largest] < arr[left])
  {
    largest = left;
  }
  if (index < arr.size() && arr[largest] < arr[right])
  {
    largest = right;
  }

  if (largest != index)
  {
    swap(arr[largest], arr[index]);
    heapify(arr, largest);
  }
}

void heapifyUtil(vector<int> &arr)
{
  int startIdx = (arr.size() / 2) - 1;
  for (int i = startIdx; i >= 0; i--)
  {
    heapify(arr, i);
  }
}

int main()
{
  vector<int> max = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
  heapifyUtil(max);
  for (auto it : max)
  {
    cout << it << " ";
  }
  return 0;
}