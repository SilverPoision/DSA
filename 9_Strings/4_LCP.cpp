class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    int n = strs.size();
    sort(strs.begin(), strs.end());

    for (auto it : strs)
      cout << it << " ";

    string ans = "";
    string start = strs[0], end = strs[n - 1];

    for (int i = 0; i < min(start.size(), end.size()); i++)
    {
      if (start[i] == end[i])
        ans += start[i];
      else
        break;
    }

    return ans;
  }
};

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    string ans = "";

    for (int i = 0; i < strs[0].size(); i++)
    {
      for (auto it : strs)
      {
        if (i == it.size() || it[i] != strs[0][i])
          return ans;
      }
      ans += strs[0][i];
    }

    return ans;
  }
};