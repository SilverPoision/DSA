class Solution
{
public:
  vector<int> maxSubsequence(vector<int> &nums, int k)
  {
    int n = nums.size();
    priority_queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
      q.push({nums[i], i});
    }

    vector<int> temp(n, 1e9);

    while (!q.empty() && k > 0)
    {
      int top = q.top().first;
      int ind = q.top().second;
      q.pop();
      temp[ind] = top;
      k--;
    }
    vector<int> ans;
    for (auto it : temp)
    {
      if (it != 1e9)
        ans.push_back(it);
    }

    return ans;
  }
};

class Solution
{
public:
  // TLE
  int maxi = -1e9;
  void f(int i, vector<int> &nums, int k, vector<int> &out, vector<int> &ans, int sum)
  {
    if (i == nums.size() || k == 0)
    {
      if (maxi < sum && out.size() >= ans.size())
      {
        maxi = sum;
        ans = out;
      }
      return;
    }

    out.push_back(nums[i]);
    f(i + 1, nums, k - 1, out, ans, sum + nums[i]);
    out.pop_back();
    f(i + 1, nums, k, out, ans, sum);
  }
  vector<int> maxSubsequence(vector<int> &nums, int k)
  {
    vector<int> out;
    vector<int> ans;
    f(0, nums, k, out, ans, 0);

    return ans;
  }
};