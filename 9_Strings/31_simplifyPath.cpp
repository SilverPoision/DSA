class Solution
{
public:
  string simplifyPath(string path)
  {
    stack<string> st;

    istringstream sstream(path);
    string seg;

    while (getline(sstream, seg, '/'))
    {
      if (seg == "." || seg == "")
        continue;
      if (seg == "..")
      {
        if (!st.empty())
          st.pop();
        continue;
      }
      st.push(seg);
    }

    string ans = "";

    while (!st.empty())
    {
      if (st.top() == "..")
      {
        st.pop();
        continue;
      }
      ans = '/' + st.top() + ans;
      st.pop();
    }

    if (ans.size() == 0)
      return "/";

    return ans;
  }
};