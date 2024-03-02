class Solution
{
public:
  int minimumDifference(vector<int> &nums)
  {
    int n = nums.size();

    int N = n / 2;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> left(N + 1), right(N + 1);

    for (int mask = 0; mask < (1 << N); mask++)
    {
      int size = 0, l = 0, r = 0;
      for (int i = 0; i < N; i++)
      {
        if (mask & (1 << i))
        {
          size++;
          l += nums[i];
          r += nums[i + N];
        }
      }
      left[size].push_back(l);
      right[size].push_back(r);
    }

    for (int sz = 0; sz <= N; ++sz)
    {
      sort(right[sz].begin(), right[sz].end());
    }

    int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

    for (int sz = 1; sz < N; ++sz)
    {
      for (auto &a : left[sz])
      {
        int b = (sum - 2 * a) / 2; // derived it see vido from utube. we have to minimize it
        int rsz = N - sz;
        auto &v = right[rsz];
        auto itr = lower_bound(v.begin(), v.end(), b);
        if (itr != v.end())
          res = min(res, abs(sum - 2 * (a + (*itr))));
      }
    }

    return res;
  }
};