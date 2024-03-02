class Solution
{
public:
  // https://leetcode.com/problems/min-cost-climbing-stairs/?envType=list&envId=opbzdrut
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();
    vector<int> dp(n + 3, 0);

    for (int i = n - 1; i >= 0; i--)
    {
      int oneStep = cost[i] + dp[i + 1];
      int twoStep = cost[i] + dp[i + 2];

      dp[i] = min(oneStep, twoStep);
    }

    return min(dp[0], dp[1]);
  }
};