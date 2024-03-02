class Solution
{
public:
  vector<vector<int>> ans;
  void f(int k, int n, vector<int> out, int sum, int num)
  {
    if (out.size() >= k)
    {
      if (out.size() == k && sum == n)
      {
        ans.push_back(out);
      }
      return;
    }

    if (num > 9)
      return;
    out.push_back(num);
    f(k, n, out, sum + num, num + 1);
    out.pop_back();
    f(k, n, out, sum, num + 1);
  }
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> out;
    f(k, n, out, 0, 1);
    return ans;
  }
};