class Solution
{
public:
  int longestValidParentheses(string s)
  {
    stack<int> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
      if (s[i] == ')' && st.empty() == 0)
      {
        int j = st.top();
        st.pop();
        s[i] = '_';
        s[j] = '_';
      }
      if (s[i] == '(')
      {
        st.push(i);
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '_')
      {
        int cnt = 1;
        i++;
        while (s[i] == '_')
        {
          i++;
          cnt++;
        }
        i--;
        ans = max(ans, cnt);
      }
    }

    return ans;
  }
};