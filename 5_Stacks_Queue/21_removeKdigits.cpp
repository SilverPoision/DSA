class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    string st = "";

    for (auto it : num)
    {
      while (k && st.size() && st.back() > it)
      {
        st.pop_back();
        k--;
      }
      if (st.size() || it != '0')
        st.push_back(it);
    }

    while (k-- && st.size())
      st.pop_back();

    return st == "" ? "0" : st;
  }
};