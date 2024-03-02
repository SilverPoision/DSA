class MyStack
{
public:
  queue<int> q1;
  queue<int> q2;
  MyStack()
  {
  }

  void push(int x)
  {
    q2.push(x);
    while (!q1.empty())
    {
      int top = q1.front();
      q2.push(top);
      q1.pop();
    }

    swap(q1, q2);
  }

  int pop()
  {
    int ele = q1.front();
    q1.pop();
    return ele;
  }

  int top()
  {
    return q1.front();
  }

  bool empty()
  {
    return q1.empty();
  }
};

// Using single queue
class MyStack
{
public:
  queue<int> q;
  MyStack()
  {
  }

  void push(int x)
  {
    q.push(x);

    int size = q.size();

    while (size - 1 != 0)
    {
      q.push(q.front());
      q.pop();
      size--;
    }
  }

  int pop()
  {
    int ele = q.front();
    q.pop();
    return ele;
  }

  int top()
  {
    return q.front();
  }

  bool empty()
  {
    return q.empty();
  }
};
