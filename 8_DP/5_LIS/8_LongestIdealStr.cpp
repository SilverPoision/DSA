class Solution
{
public:
  // https://leetcode.com/problems/longest-ideal-subsequence/submissions/1241545685/?envType=daily-question&envId=2024-04-25
  // https://www.youtube.com/watch?v=01nYV8eqxm8&t=1s
  int longestIdealString(string s, int k)
  {
    int n = s.size();

    vector<int> dp(26, 0);
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
      int ind = s[i] - 'a';
      int longest = 0;
      for (int prev = max(ind - k, 0); prev <= min(25, ind + k); prev++)
      {
        longest = max(longest, dp[prev]);
      }
      dp[ind] = max(dp[ind], longest + 1);
      maxi = max(maxi, dp[ind]);
    }

    return maxi;
  }
};