class Solution
{
public:
  string removeOuterParentheses(string s)
  {
    int cnt = 0;
    string ans = "";

    for (auto it : s)
    {
      if (it == '(')
      {
        cnt++;
      }
      else if (it == ')')
      {
        cnt--;
      }

      if (cnt > 1 && it == '(')
      {
        ans += it;
      }
      else if (cnt > 0 && it == ')')
      {
        ans += it;
      }
    }

    return ans;
  }
};