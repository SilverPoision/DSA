#include <bits/stdc++.h>

int precendence(char ch)
{
  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  else
    return -1;
}

string infixToPostfix(string exp)
{
  // Write your code here
  string result = "";
  stack<char> st;

  for (int i = 0; i < exp.length(); i++)
  {
    char ch = exp[i];

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
      result += ch;
    }
    else if (ch == '(')
    {
      st.push(ch);
    }
    else if (ch == ')')
    {
      while (st.top() != '(')
      {
        result += st.top();
        st.pop();
      }
      st.pop();
    }
    else
    {
      while (!st.empty() && (precendence(ch) <= precendence(st.top())))
      {
        result += st.top();
        st.pop();
      }
      st.push(ch);
    }
  }

  while (!st.empty())
  {
    result += st.top();
    st.pop();
  }

  return result;
}