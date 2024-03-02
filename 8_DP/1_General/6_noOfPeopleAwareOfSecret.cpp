class Solution
{
public:
  // https://leetcode.com/problems/number-of-people-aware-of-a-secret/
  int mod = 1e9 + 7;
  int peopleAwareOfSecret(int n, int delay, int forget)
  {
    vector<long> dp(n + 1, 0);
    long noOfpeopleSharingSecret = 0;
    dp[1] = 1;
    long ans = 0;

    for (int i = 2; i <= n; i++)
    {
      long noOfNewPeopleSharing = dp[max(0, i - delay)];
      long noOfPeopleForgetting = dp[max(0, i - forget)];
      noOfpeopleSharingSecret +=
          (noOfNewPeopleSharing - noOfPeopleForgetting + mod) % mod;

      dp[i] = noOfpeopleSharingSecret;
    }

    for (int i = n - forget + 1; i <= n; i++)
    {
      ans += dp[i] % mod;
    }

    return ans % mod;
  }
};