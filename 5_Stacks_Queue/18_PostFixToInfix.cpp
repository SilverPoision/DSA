string postToInfix(string s)
{
  // Write your code here.
  stack<string> st;
  string res;

  for (int i = 0; i < s.size(); i++)
  {
    char c = s[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
      string temp = "";
      temp += c;
      st.push(temp);
    }
    else
    {
      string a = st.top();
      st.pop();
      string b = st.top();
      st.pop();

      string temp = "";
      temp += '(';
      temp += b;
      temp += c;
      temp += a;
      temp += ')';

      st.push(temp);
    }
  }

  while (!st.empty())
  {
    res += st.top();
    st.pop();
  }

  return res;
}