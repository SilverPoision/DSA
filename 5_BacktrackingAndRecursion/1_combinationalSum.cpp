class Solution
{
public:
  void f(int i, vector<int> &candi, int target, vector<vector<int>> &ans, vector<int> &out)
  {
    if (i >= candi.size() || target <= 0)
    {
      if (target == 0)
      {
        ans.push_back(out);
      }
      return;
    }
    out.push_back(candi[i]);
    f(i, candi, target - candi[i], ans, out);
    out.pop_back();
    f(i + 1, candi, target, ans, out);
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<vector<int>> ans;
    vector<int> out;
    f(0, candidates, target, ans, out);
    return ans;
  }
};