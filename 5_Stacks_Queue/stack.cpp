// Stack class.
class Stack
{

public:
  int cap;
  vector<int> st;
  int size = 0;

  Stack(int capacity)
  {
    // Write your code here.
    cap = capacity;
    st.resize(capacity);
  }

  void push(int num)
  {
    // Write your code here.
    if (size == cap)
      return;
    st.push_back(num);
    size++;
  }

  int pop()
  {
    // Write your code here.
    if (size == 0)
    {
      return -1;
    }
    int back = st.back();
    st.pop_back();
    size--;
    return back;
  }

  int top()
  {
    // Write your code here.
    if (size == 0)
      return -1;
    return st.back();
  }

  int isEmpty()
  {
    // Write your code here.
    return size == 0;
  }

  int isFull()
  {
    // Write your code here.
    return size == cap;
  }
};
