class Solution
{
public:
  string findLongestWord(string s, vector<string> &dict)
  {
    vector<string> ans;
    for (auto it : dict)
    {
      int i = 0;
      int j = 0;
      string temp = "";
      while (i < s.size() && j < it.size())
      {
        if (s[i] == it[j])
        {
          temp += s[i++];
          j++;
        }
        else
        {
          i++;
        }
      }
      if (temp == it)
      {
        if (ans.size() > 0 && ans.back().size() <= temp.size())
        {
          if (ans.back().size() < temp.size())
            ans.clear();
          ans.push_back(temp);
        }
        if (ans.empty())
        {
          ans.push_back(temp);
        }
      }
    }

    if (ans.size() > 0)
    {
      sort(ans.begin(), ans.end());
      return ans[0];
    }

    return "";
  }
};

// more elegant
class Solution
{
public:
  bool matchPattern(string s, string t)
  {
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size())
    {
      if (s[i] == t[j])
      {
        i++;
        j++;
      }
      else
      {
        i++;
      }
    }

    return j == t.size();
  }
  string findLongestWord(string s, vector<string> &dict)
  {
    sort(dict.begin(), dict.end());
    string maxString = "";
    for (auto it : dict)
    {
      if (matchPattern(s, it))
      {
        maxString = it.size() > maxString.size() ? it : maxString;
      }
    }

    return maxString;
  }
};