class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<long> st;

    for (auto it : tokens)
    {
      if (it == "*" || it == "/" || it == "-" || it == "+")
      {
        long x = st.top();
        st.pop();
        long y = st.top();
        st.pop();
        if (it == "*")
        {
          st.push(y * x);
        }
        else if (it == "/")
        {
          st.push(y / x);
        }
        else if (it == "-")
        {
          st.push(y - x);
        }
        else
        {
          st.push(y + x);
        }
      }
      else
      {
        int n = stoi(it);
        st.push(n);
      }
    }
    return st.top();
  }
};