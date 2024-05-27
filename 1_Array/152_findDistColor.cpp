class Solution
{
public:
  // https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/
  vector<int> queryResults(int limit, vector<vector<int>> &q)
  {
    vector<int> ans;

    unordered_map<int, int> ctoint;
    unordered_map<int, int> intoc;

    for (auto it : q)
    {
      int ind = it[0];
      int col = it[1];

      if (intoc.find(ind) != intoc.end())
      {
        if (--ctoint[intoc[ind]] == 0)
          ctoint.erase(intoc[ind]);
      }
      ctoint[col]++;
      intoc[ind] = col;

      ans.push_back(ctoint.size());
    }

    return ans;
  }
};