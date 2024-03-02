class Solution
{
public:
  // https://leetcode.com/problems/constrained-subsequence-sum/
  // https://www.youtube.com/watch?v=-IYZv-nOSys
  int constrainedSubsetSum(vector<int> &nums, int k)
  {
    int n = nums.size();
    int res = nums[0];
    priority_queue<pair<int, int>> q; // the time complexity is nlogn but it can be
    // reduces to n with dqueue
    q.push({nums[0], 0});

    for (int i = 1; i < n; i++)
    {
      while (i - q.top().second > k)
        q.pop();

      int curMax = max(nums[i], nums[i] + q.top().first);
      res = max(res, curMax);
      q.push({curMax, i});
    }

    return res;
  }
};

class Solution
{
public:
  // solved with dequeue
  // o(n)
  int constrainedSubsetSum(vector<int> &nums, int k)
  {
    int n = nums.size();
    int res = nums[0];
    deque<pair<int, int>> q;
    q.push_front({nums[0], 0});

    for (int i = 1; i < n; i++)
    {
      while (!q.empty() && i - q.front().second > k)
        q.pop_front();

      int curMax = max(nums[i], nums[i] + q.front().first);
      res = max(res, curMax);
      while (!q.empty() && curMax > q.back().first)
        q.pop_back();
      q.push_back({curMax, i});
    }

    return res;
  }
};

class Solution
{
public:
  // tle
  int f(int i, int k, vector<int> &nums, int prev, vector<vector<int>> &dp)
  {
    if (i == nums.size())
    {
      if (prev == -1)
        return -1e9;
      return 0;
    }

    if (dp[i][prev + 1] != -1)
      return dp[i][prev + 1];

    int notTake = f(i + 1, k, nums, prev, dp);
    int take = -1e9;
    if (prev == -1 || i - prev <= k)
    {
      take = nums[i] + f(i + 1, k, nums, i, dp);
    }

    return dp[i][prev + 1] = max(take, notTake);
  }
  int constrainedSubsetSum(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, k, nums, -1, dp);
  }
};