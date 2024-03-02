
class Solution
{
public:
  void insertAtBottom(int x, stack<int> &st)
  {
    if (st.empty())
    {
      st.push(x);
      return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(x, st);
    st.push(temp);
  }
  void Reverse(stack<int> &st)
  {
    vector<int> store;

    if (!st.empty())
    {
      int x = st.top();
      st.pop();

      Reverse(st);

      insertAtBottom(x, st);
    }
  }
};