#define ll long long

class Solution
{
public:
  // https://leetcode.com/problems/the-number-of-good-subsets
  // https://leetcode.com/problems/the-number-of-good-subsets/solutions/4623728/one-of-the-best-bitmasking-question-beats-90-runtime-cpp-dp-bitmasking
  vector<int> primes;
  int mod = 1e9 + 7;
  int getMask(int num)
  {
    int mask = 0;

    for (int i = 0; i < 10; i++)
    {
      int cnt = 0;
      while (num % primes[i] == 0)
      {
        cnt++;
        num /= primes[i];
      }

      if (cnt > 1)
        return -1;
      if (cnt == 1)
      {
        mask |= (1 << i);
      }
    }

    return mask;
  }

  ll f(int i, vector<int> &cnt, int mask, vector<vector<ll>> &dp,
       vector<int> &primeMask)
  {
    if (i == 31)
    {
      return mask != 0;
    }

    if (dp[i][mask] != -1)
      return dp[i][mask];

    if (cnt[i] == 0 || primeMask[i] == -1)
      return dp[i][mask] = f(i + 1, cnt, mask, dp, primeMask) % mod;

    ll ans = f(i + 1, cnt, mask, dp, primeMask) % mod;
    if ((mask & primeMask[i]) == 0)
    {
      ans = (ans + ((f(i + 1, cnt, (mask | primeMask[i]), dp, primeMask) % mod) * cnt[i]) % mod) % mod;
    }

    return dp[i][mask] = ans % mod;
  }
  int numberOfGoodSubsets(vector<int> &nums)
  {
    int n = nums.size();

    vector<vector<ll>> dp(31, vector<ll>(1 << 11, -1));
    // all the prime numbers between 30
    primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    vector<int> primeMask(31, 0), cnt(31, 0);
    // Making the frequency array
    for (auto it : nums)
      cnt[it]++;
    // Building the mask of all the numbers under 31
    for (int i = 2; i < 31; i++)
    {
      primeMask[i] = getMask(i);
    }
    primeMask[1] = -1;

    ll res = f(2, cnt, 0, dp, primeMask);
    long long op = 1;
    // all combination sets of 1
    for (int i = 0; i < cnt[1]; i++)
      op = (op * 2) % mod;
    return (res * op) % mod;
  }
};

// =============================

#define ll long long

class Solution
{
public:
  // tle
  vector<int> primes;
  int mod = 1e9 + 7;
  ll getMask(ll num)
  {
    ll mask = 0;

    for (int i = 0; i < 10; i++)
    {
      int cnt = 0;
      while (num % primes[i] == 0)
      {
        cnt++;
        num /= primes[i];
      }

      if (cnt > 1)
        return -1;
      if (cnt == 1)
      {
        mask |= (1 << i);
      }
    }

    return mask;
  }

  ll f(int i, vector<int> &nums, int mask, vector<vector<ll>> &dp)
  {
    if (i >= nums.size())
    {
      if (mask != 0)
        return 1;
      return 0;
    }

    if (dp[i][mask] != -1)
      return dp[i][mask];

    ll ans = f(i + 1, nums, mask, dp);
    ll newMask = getMask(nums[i]);
    if (newMask != -1 && (mask & newMask) == 0)
    {
      ans = (ans + f(i + 1, nums, mask | newMask, dp)) % mod;
    }

    return dp[i][mask] = ans;
  }
  int numberOfGoodSubsets(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<ll>> dp(n, vector<ll>(1 << 10, -1));
    primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    return f(0, nums, 0, dp) % mod;
  }
}

// tab
#define ll long long

class Solution
{
public:
  // tle
  vector<int> primes;
  int mod = 1e9 + 7;
  ll getMask(ll num)
  {
    ll mask = 0;

    for (int i = 0; i < 10; i++)
    {
      int cnt = 0;
      while (num % primes[i] == 0)
      {
        cnt++;
        num /= primes[i];
      }

      if (cnt > 1)
        return -1;
      if (cnt == 1)
      {
        mask |= (1 << i);
      }
    }

    return mask;
  }
  int numberOfGoodSubsets(vector<int> &nums)
  {
    int n = nums.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(1 << 11, 1));
    dp[n][0] = 0;
    primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    vector<ll> ma(31, 0);
    for (int i = 0; i < n; i++)
    {
      if (ma[nums[i]] == 0)
        ma[nums[i]] = getMask(nums[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
      for (int mask = 1 << 10; mask >= 0; mask--)
      {
        ll ans = dp[i + 1][mask];
        ll newMask = ma[nums[i]];
        if (newMask != -1 && (mask & newMask) == 0)
        {
          ans = (ans + dp[i + 1][mask | newMask]) % mod;
        }

        dp[i][mask] = ans;
      }
    }

    return dp[0][0];
  }
};