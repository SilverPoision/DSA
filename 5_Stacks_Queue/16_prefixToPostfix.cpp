string preToPost(string s)
{
  // Write Your Code Here
  stack<string> st;
  string res;

  for (int i = s.size() - 1; i >= 0; i--)
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
      temp += a;
      temp += b;
      temp += c;

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