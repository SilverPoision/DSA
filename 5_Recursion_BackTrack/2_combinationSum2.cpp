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

    if (target < candi[i])
      return;

    out.push_back(candi[i]);
    f(i + 1, candi, target - candi[i], ans, out);
    out.pop_back();
    while (i + 1 < candi.size() && candi[i] == candi[i + 1])
    {
      i++;
    }
    f(i + 1, candi, target, ans, out);
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    vector<vector<int>> ans;
    vector<int> out;
    sort(candidates.begin(), candidates.end());
    f(0, candidates, target, ans, out);
    return ans;
  }
};