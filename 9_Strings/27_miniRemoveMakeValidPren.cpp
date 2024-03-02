class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    stack<int> st, remove;
    int open = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != '(' && s[i] != ')')
        continue;

      if (s[i] == '(')
      {
        st.push(i);
        open++;
      }
      else if (s[i] == ')' && open > 0)
      {
        st.pop();
        open--;
      }
      else
      {
        remove.push(i);
      }
    }

    while (!remove.empty() || !st.empty())
    {
      if (!remove.empty())
      {
        s[remove.top()] = ' ';
        remove.pop();
      }

      if (!st.empty())
      {
        s[st.top()] = ' ';
        st.pop();
      }
    }

    string ans = "";
    for (auto it : s)
    {
      if (it != ' ')
        ans.push_back(it);
    }
    return ans;
  }
};