class Solution
{
public:
  void helper(int k, int n, vector<int> &out, vector<vector<int>> &ans, int prevInd)
  {
    if (k == 0 && n == 0)
    {
      ans.push_back(out);
      return;
    }
    if (k == 0)
      return;
    if (n == 0)
      return;

    for (int ind = prevInd; ind <= 9; ind++)
    {
      if (ind > n)
        break;
      out.push_back(ind);
      helper(k - 1, n - ind, out, ans, ind + 1);
      out.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<vector<int>> ans;
    vector<int> out;
    if (n < k || n == 1)
      return ans;
    helper(k, n, out, ans, 1);
    return ans;
  }
};