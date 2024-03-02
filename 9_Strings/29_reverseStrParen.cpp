class Solution
{
public:
  string reverseParentheses(string s)
  {
    int n = s.size();

    string ans;
    stack<char> st;
    queue<char> qt;
    for (int i = 0; i < n; i++)
    {

      if (s[i] == ')')
      {

        while (st.top() != '(')
        {
          qt.push(st.top());
          st.pop();
        }

        st.pop();

        while (!qt.empty())
        {
          st.push(qt.front());
          qt.pop();
        }
      }
      else
      {
        st.push(s[i]);
      }
    }

    while (!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};