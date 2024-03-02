#define ll long long

/*
The whole intuition is we calculate the no of subsets via the dfs function and
in the mean time we also monitor that if any of the prime factor of nums[i]
that is begin included in the subset has no prime factors same as any of the prime
factors of the elements of the subsets. The mask is wokring like sort of a hash
that stores that which prime factors have been used till yet.
we can not include 2 PrimeFactors because then they will form a square and will defeat the whole
purpose of the solution.
*/

class Solution
{
public:
  // https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/
  // https://leetcode.com/problems/count-the-number-of-square-free-subsets/solutions/3203707/dp-bitmask-c-prime-factorization/
  vector<int> primes;
  int mod = 1e9 + 7;
  ll getMask(ll num)
  {
    ll mask = 0;

    for (int i = 0; i < 10; i++)
    {
      int times = 0;
      while (num % primes[i] == 0)
      {
        times++;
        num /= primes[i];
      }

      if (times > 1)
        return -1;
      if (times == 1)
      {
        mask |= (1 << i); // set those bits that have been used in this loop yet
      }
    }

    return mask;
  }

  ll dfs(int i, vector<int> &nums, vector<vector<ll>> &dp, ll prodMask)
  {
    if (i >= nums.size())
      return 1;

    if (dp[i][prodMask] != -1)
      return dp[i][prodMask];

    ll ans = dfs(i + 1, nums, dp, prodMask);

    ll mask = getMask(nums[i]);
    if (mask != -1 && (mask & prodMask) == 0)
    {
      ans = (ans + dfs(i + 1, nums, dp, prodMask | mask)) % mod;
    }

    return dp[i][prodMask] = ans;
  }

  int squareFreeSubsets(vector<int> &nums)
  {
    int n = nums.size();
    primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<vector<ll>> dp(n, vector<ll>(1 << 10, -1)); // this 1 << 10 is because the size of the mask is around that number
    return (dfs(0, nums, dp, 0) - 1 + mod) % mod;      // subtracting this one to exclude the empty arr one.
  }
};