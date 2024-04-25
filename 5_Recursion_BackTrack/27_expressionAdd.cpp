class Solution
{
public:
  string s;
  int target;
  vector<string> ans;
  vector<string> addOperators(string num, int target)
  {
    this->s = num;
    this->target = target;
    f(0, "", 0, 0);
    return ans;
  }

  void f(int i, const string &path, long res, long prevNum)
  {
    if (i == s.length())
    {
      if (target == res)
        ans.push_back(path);
      return;
    }

    string numStr;
    long num = 0;

    for (int j = i; j < s.length(); j++)
    {
      if (j > i && s[i] == '0')
        break;
      numStr += s[j];
      num = num * 10 + s[j] - '0';

      if (i == 0)
      {
        f(j + 1, path + numStr, num, num);
      }
      else
      {
        f(j + 1, path + "+" + numStr, res + num, num);
        f(j + 1, path + "-" + numStr, res - num, -num);
        f(j + 1, path + "*" + numStr, res - prevNum + prevNum * num, prevNum * num);
      }
    }
  }
};