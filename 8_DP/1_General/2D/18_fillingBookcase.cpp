class Solution
{
public:
  // we are not memoising maxH because when it changes the already one of two
  // params change so we already got a unique combi
  // https://leetcode.com/problems/filling-bookcase-shelves/?envType=daily-question&envId=2024-07-31
  vector<vector<int>> dp;
  int solve(int i, vector<vector<int>> &b, int sw, int currW, int maxH)
  {
    if (i == b.size())
    {
      return maxH;
    }

    if (dp[i][currW] != -1)
      return dp[i][currW];

    int newSelf = 1e9, existingSelf = 1e9;

    if (currW + b[i][0] <= sw)
    {
      existingSelf =
          solve(i + 1, b, sw, currW + b[i][0], max(maxH, b[i][1]));
    }
    if (maxH != 0)
      newSelf = maxH + solve(i + 1, b, sw, b[i][0], b[i][1]);

    return dp[i][currW] = min(existingSelf, newSelf);
  }
  int minHeightShelves(vector<vector<int>> &b, int sw)
  {
    dp = vector<vector<int>>(
        b.size(), vector<int>(sw + 1, -1));
    return solve(0, b, sw, 0, 0);
  }
};