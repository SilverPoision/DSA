class Solution
{
public:
  // https://leetcode.com/problems/high-access-employees/
  bool isHighAccess(multiset<int> &at)
  {
    vector<int> access(at.begin(), at.end());
    int start = 0, end = 2;

    while (start < end && end < access.size())
    {
      if ((access[end] - access[start]) < 100)
      {
        return true;
      }
      start++;
      end++;
    }

    return false;
  }
  vector<string> findHighAccessEmployees(vector<vector<string>> &at)
  {
    unordered_map<string, multiset<int>> hash;
    vector<string> ans;

    for (auto it : at)
    {
      hash[it[0]].insert(stoi(it[1]));
    }

    for (auto it : hash)
    {
      if (it.second.size() < 3)
        continue;
      // cout << isHighAccess(it.second);
      if (isHighAccess(it.second))
        ans.push_back(it.first);
    }

    return ans;
  }
};