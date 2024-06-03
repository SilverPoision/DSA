class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1
  vector<vector<int>> dp;
  int solve(int i, vector<int> &cost, int w)
  {
    if (w < 0 || i >= cost.size())
      return 1e9;
    if (w == 0)
      return 0;

    if (dp[i][w] != -1)
      return dp[i][w];

    int take = 1e9;
    if (cost[i] != -1)
      take = cost[i] + solve(i, cost, w - (i + 1));
    int notTake = solve(i + 1, cost, w);

    return dp[i][w] = min(take, notTake);
  }
  int minimumCost(int n, int w, vector<int> &cost)
  {
    // code here
    dp = vector<vector<int>>(n, vector<int>(w + 1, -1));
    int res = solve(0, cost, w);

    return res == 1e9 ? -1 : res;
  }
};

// class Solution {
public:
int minimumCost(int n, int W, vector<int> &cost)
{
  const int INF = 1e8;
  vector<int> prev(W + 1, INF);
  prev[0] = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int w = 1; w <= W; w++)
    {
      int take = INF, nottake = prev[w];
      if (i + 1 <= w && cost[i] != -1)
        take = cost[i] + prev[w - (i + 1)];
      prev[w] = min(take, nottake);
    }
  }

  int ans = prev[W];
  if (ans >= INF)
    ans = -1;
  return ans;
}
}
;