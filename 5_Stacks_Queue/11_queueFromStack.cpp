class MyQueue
{
public:
  stack<int> s1;
  stack<int> s2;
  MyQueue()
  {
  }

  void push(int x)
  {
    while (!s1.empty())
    {
      s2.push(s1.top());
      s1.pop();
    }

    s1.push(x);

    while (!s2.empty())
    {
      s1.push(s2.top());
      s2.pop();
    }
  }

  int pop()
  {
    int ele = s1.top();
    s1.pop();
    return ele;
  }

  int peek()
  {
    return s1.top();
  }

  bool empty()
  {
    return s1.empty();
  }
};

// Somewhat optimized amortized O(1)
class MyQueue
{
public:
  stack<int> in;
  stack<int> out;
  MyQueue()
  {
  }

  void push(int x)
  {
    in.push(x);
  }

  int pop()
  {
    if (out.empty())
    {
      while (!in.empty())
      {
        out.push(in.top());
        in.pop();
      }
    }
    int ele = out.top();
    out.pop();
    return ele;
  }

  int peek()
  {
    if (out.empty())
    {
      while (!in.empty())
      {
        out.push(in.top());
        in.pop();
      }
    }

    return out.top();
  }

  bool empty()
  {
    if (out.empty())
    {
      while (!in.empty())
      {
        out.push(in.top());
        in.pop();
      }
    }

    return out.empty();
  }
};
