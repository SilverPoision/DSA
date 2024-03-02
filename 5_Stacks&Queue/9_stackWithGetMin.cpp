class MinStack
{
public:
  stack<long long> st;
  long long mini;
  MinStack()
  {
    mini = 1e9;
  }

  void push(int val)
  {
    long long v = (long long)val;
    if (st.empty())
    {
      st.push(v);
      mini = v;
    }
    else
    {
      if (v < mini)
      {
        st.push(2 * v - mini);
        mini = v;
      }
      else
      {
        st.push(v);
      }
    }
  }

  void pop()
  {
    if (st.empty())
    {
      return;
    }
    if (st.top() < mini)
    {
      mini = 2 * mini - st.top();
    }
    st.pop();
  }

  int top()
  {
    if (st.empty())
      return -1;
    if (st.top() < mini)
    {
      return mini;
    }
    else
    {
      return st.top();
    }
  }

  int getMin()
  {
    return mini;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */