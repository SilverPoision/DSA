#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
  vector<int> arr;

  Heap(vector<int> arr)
  {
    this->arr = arr;
    int ind = arr.size() / 2 - 1;
    for (int i = ind; i >= 0; i--)
    {
      heapify(i);
    }
  }

  void printList()
  {
    for (auto it : arr)
    {
      cout << it << " ";
    }
    cout << endl;
  }

  void heapify(int index)
  {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int largest = index;

    if (left < arr.size() && arr[largest] < arr[left])
    {
      largest = left;
    }

    if (right < arr.size() && arr[largest] < arr[right])
    {
      largest = right;
    }

    if (largest != index)
    {
      swap(arr[index], arr[largest]);
      heapify(largest);
    }
  }

  void increaseKey(int key, int value)
  {
    if (arr[key] > value)
      return;

    arr[key] = value;
    while (key > 0 && arr[key] > arr[(key - 1) / 2])
    {
      swap(arr[key], arr[(key - 1) / 2]);
      key = (key - 1) / 2;
    }
  }

  void decreseKey(int key, int value)
  {
    if (arr[key] < value)
      return;

    arr[key] = value;
    heapify(key);
  }

  void push(int a)
  {
    int key = arr.size();
    arr.push_back(a);

    while (key > 0 && arr[key] > arr[(key - 1) / 2])
    {
      swap(arr[key], arr[(key - 1) / 2]);
      key = (key - 1) / 2;
    }
  }

  void pop(int key)
  {
    swap(arr[key], arr[arr.size() - 1]);
    arr.pop_back();
    heapify(key);
  }

  int extractKey()
  {
    if (arr.size() < 1)
      return -1;

    int max = arr[0];
    arr[0] = arr[arr.size() - 1];
    heapify(0);
    arr.pop_back();
    return max;
  }

  int mini()
  {
    int mini = 1e9;
    for (auto it : arr)
    {
      mini = min(mini, it);
    }
    return mini;
  }
};

int main()
{
  vector<int> arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
  Heap *h = new Heap(arr);
  vector<int> res;
  for (int i = 0; i < h->arr.size(); i++)
  {
    // this is heap sort
    res.push_back(h->extractKey());
  }

  for (auto it : res)
  {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}

class minHeap
{
public:
  // Constructor for the class.
  vector<int> arr;
  minHeap(int size)
  {
    // Write your code here.
  }

  void heapify(int key)
  {
    int mini = key;
    int left = 2 * key + 1;
    int right = 2 * key + 2;
    int size = arr.size();

    if (left < size && arr[left] < arr[mini])
    {
      mini = left;
    }
    if (right < size && arr[right] < arr[mini])
    {
      mini = right;
    }

    if (mini != key)
    {
      swap(arr[key], arr[mini]);
      heapify(mini);
    }
  }

  // Implement the function to remove minimum element.
  int extractMinElement()
  {
    // Write you code here.
    if (arr.size() == 0)
      return -1;
    int mini = arr[0];

    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    heapify(0);

    return mini;
  }

  // Implement the function to delete an element.
  void deleteElement(int ind)
  {
    // Write you code here.
    if (arr.size() < ind + 1)
      return;

    arr[ind] = INT_MIN;
    while (ind > 0 && arr[ind] < arr[(ind - 1) / 2])
    {
      swap(arr[ind], arr[(ind - 1) / 2]);
      ind = (ind - 1) / 2;
    }

    extractMinElement();
  }

  // Implement the function to insert 'val' in the heap.
  void insert(int val)
  {
    // Write you code here.
    arr.push_back(val);
    int ind = arr.size() - 1;

    while (ind > 0 && arr[(ind - 1) / 2] > arr[ind])
    {
      swap(arr[(ind - 1) / 2], arr[ind]);
      ind = (ind - 1) / 2;
    }
  }
};