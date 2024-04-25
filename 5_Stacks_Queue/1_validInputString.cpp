class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> st;
    if (s.size() % 2 == 1)
      return false;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '{')
      {
        st.push('}');
      }
      else if (s[i] == '(')
      {
        st.push(')');
      }
      else if (s[i] == '[')
      {
        st.push(']');
      }
      else if (!st.empty())
      {
        char top = st.top();
        st.pop();
        if (top != s[i])
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    return st.empty();
  }
};