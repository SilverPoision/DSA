class Solution
{
public:
  // https://leetcode.com/problems/make-the-string-great/?envType=daily-question&envId=2024-04-05
  string makeGood(string s)
  {
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
      while (!ans.empty() && abs(s[i] - ans.back()) == 32)
      {
        ans.pop_back();
        i++;
      }
      if (i == s.length())
        break;
      ans.push_back(s[i]);
    }
    return ans;
  }
};

//
class Solution
{
public:
  string makeGood(string s)
  {
    int i = 0;
    string t = "";
    while (true)
    {
      t = "";
      bool flag = true;
      i = 0;
      while (i < s.size())
      {
        if (i < s.size() - 1 && (isupper(s[i]) && tolower(s[i]) == s[i + 1]) ||
            (isupper(s[i + 1]) && tolower(s[i + 1]) == s[i]))
        {
          flag = false;
          i += 2;
          continue;
        }
        else
        {
          t += s[i++];
        }
      }
      swap(s, t);
      if (flag)
        return s;
    }

    return s;
  }
};