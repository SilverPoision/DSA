class Queue
{

  int front, rear, size;
  vector<int> arr;

public:
  Queue()
  {
    front = 0;
    rear = 0;
    arr.resize(100001);
    size = 0;
  }

  // Enqueue (add) element 'e' at the end of the queue.
  void enqueue(int e)
  {
    // Write your code here.
    if (size == 0)
    {
      arr[rear] = e;
      size++;
      return;
    }

    rear++;
    arr[rear] = e;
    size++;
    return;
  }

  // Dequeue (retrieve) the element from the front of the queue.
  int dequeue()
  {
    // Write your code here.
    if (size == 0)
      return -1;
    int ele = arr[front];
    front++;
    size--;
    if (size == 0)
      front = rear;
    return ele;
  }
};

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
  vector<int> arr;

  int front()
  {
    return arr[0];
  }

  bool isEmpty()
  {
    return (arr.size() == 0);
  }

  int pop()
  {
    arr.erase(arr.begin());
    return 1;
  }

  int push(int i)
  {
    arr.push_back(i);
    return i;
  }
  void printStack()
  {
    for (auto it : arr)
    {
      cout << it << endl;
    }
    cout << endl;
    cout << endl;
  }
};

int main()
{
  Queue *que = new Queue();
  cout << que->isEmpty() << endl;
  que->push(1);
  que->push(2);
  que->push(3);
  que->printStack();
  que->push(4);
  que->push(5);
  que->printStack();
  que->pop();
  cout << que->isEmpty() << endl;

  que->printStack();
  cout << que->front();

  return 0;
}