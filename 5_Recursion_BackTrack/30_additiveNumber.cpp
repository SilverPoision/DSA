class Solution
{
public:
  // https://leetcode.com/problems/additive-number/
  bool dfs(long long n1, long long n2, string num, bool isEnd)
  {
    if (num.size() == 0 && isEnd)
      return true;

    string t = to_string(n1 + n2);
    int n = t.size();
    if (t != num.substr(0, n))
      return false;
    return dfs(n2, n1 + n2, num.substr(n), true);
  }
  bool isAdditiveNumber(string num)
  {
    int n = num.size();

    for (int i = 1; i < n - 1; i++)
    {
      string sub = num.substr(0, i);
      long long n1 = stoll(sub);
      if (to_string(n1) != sub)
        break;
      for (int j = i + 1; j < n; j++)
      {
        string sub2 = num.substr(i, j - i);
        long long n2 = stoll(sub2);
        if (to_string(n2) != sub2)
          break;
        if (dfs(n1, n2, num.substr(j), false))
          return true;
      }
    }

    return false;
  }
};