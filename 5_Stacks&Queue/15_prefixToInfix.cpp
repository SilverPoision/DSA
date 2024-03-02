string prefixToInfixConversion(string &s)
{
  // Write your code here.
  string res = "";
  stack<string> st;

  for (int i = s.size() - 1; i >= 0; i--)
  {
    char c = s[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
      string ch = "";
      ch += c;
      st.push(ch);
    }
    else
    {
      string a = st.top();
      st.pop();
      string b = st.top();
      st.pop();

      string pu = "";
      pu += '(';
      pu += a;
      pu += c;
      pu += b;
      pu += ')';

      st.push(pu);
    }
  }

  while (!st.empty())
  {
    res += st.top();
    st.pop();
  }

  return res;
}
