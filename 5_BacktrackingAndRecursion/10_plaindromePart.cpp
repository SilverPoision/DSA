class Solution
{
public:
  bool isPali(string &s, int start, int end)
  {
    while (start <= end)
    {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }

  void helper(int i, string &s, vector<string> &out, vector<vector<string>> &ans)
  {
    if (i == s.size())
    {
      ans.push_back(out);
      return;
    }

    for (int index = i; index < s.size(); index++)
    {
      if (isPali(s, i, index))
      {
        out.push_back(s.substr(i, index - i + 1));
        helper(index + 1, s, out, ans);
        out.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> ans;
    vector<string> out;
    helper(0, s, out, ans);
    return ans;
  }
};