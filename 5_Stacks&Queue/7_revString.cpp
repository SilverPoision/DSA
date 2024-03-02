#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    stack<string> st;
    string str = "";

    for (int i = 0; i <= s.size(); i++)
    {
      if (s[i] == ' ' || i == s.size())
      {
        if (str.size() > 0)
          st.push(str);
        str = "";
        continue;
      }

      str += s[i];
    }

    string ans = "";

    while (!st.empty())
    {
      ans += st.top();
      ans += " ";
      st.pop();
    }

    return ans.substr(0, ans.size() - 1);
  }
};

int main()
{
  Solution st;
  string s = "i like this program very much";
  cout << st.reverseWords(s);
  return 0;
}