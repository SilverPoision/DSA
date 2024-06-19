class Solution
{
public:
  // https://leetcode.com/problems/maximum-total-reward-using-operations-i/
  vector<vector<int>> dp;
  int solve(int i, vector<int> &r, int x)
  {
    if (i == r.size() || x >= r.back())
      return x;

    if (dp[i][x] != -1)
      return dp[i][x];

    int ans = 0;

    if (x < r[i])
    {
      ans = max(ans, solve(i + 1, r, x + r[i]));
    }
    ans = max(ans, solve(i + 1, r, x));

    return dp[i][x] = ans;
  }
  int maxTotalReward(vector<int> &r)
  {
    sort(r.begin(), r.end());
    dp = vector<vector<int>>(r.size(), vector<int>(r.back() + 1, -1));
    return solve(0, r, 0);
  }
};