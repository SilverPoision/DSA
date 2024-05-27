class Solution
{
public:
  // https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/
  long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
  {
    vector<long long> delta;
    for (auto it : nums)
    {
      delta.push_back((it ^ k) - it);
    }

    sort(delta.begin(), delta.end(), greater<int>());

    long long res = accumulate(nums.begin(), nums.end(), (long long)0);

    for (int i = 0; i < delta.size(); i += 2)
    {
      if (i == delta.size() - 1)
        break;
      long long path_delta = delta[i] + delta[i + 1];

      if (path_delta <= 0)
        break;
      res = res + path_delta;
    }

    return res;
  }
};