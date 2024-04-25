class Solution
{
public:
  void helper(int index, string &digits, vector<string> &mob, vector<string> &ans, string st)
  {
    if (st.size() == digits.size())
    {
      ans.push_back(st);
      return;
    }
    int num = digits[index] - '0';
    string str = mob[num];
    for (int i = 0; i < str.size(); i++)
    {
      st += str[i];
      helper(index + 1, digits, mob, ans, st);
      st.pop_back();
    }
  }
  vector<string> letterCombinations(string digits)
  {
    vector<string> ans;
    if (digits == "")
      return ans;
    vector<string> mob = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    helper(0, digits, mob, ans, "");
    return ans;
  }
};