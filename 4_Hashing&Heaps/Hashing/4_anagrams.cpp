class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> ans;
    if (strs.size() == 0)
      return ans;

    map<string, vector<string>> m;

    for (auto it : strs)
    {
      string temp = it;
      sort(temp.begin(), temp.end());
      m[temp].push_back(it);
    }

    for (auto it : m)
    {
      ans.push_back(it.second);
    }

    return ans;
  }
};