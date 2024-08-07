class Solution
{
public:
  // https://www.youtube.com/watch?v=oMHO5iti5_c
  // https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/submissions/1346665094/?envType=daily-question&envId=2024-08-04
  typedef pair<int, int> P;
  int M = 1e9 + 7;

  int rangeSum(vector<int> &nums, int n, int left, int right)
  {
    priority_queue<P, vector<P>, greater<P>> pq;

    // pair<sum, i> -> (subarray sum, till index i)
    for (int i = 0; i < n; i++)
    {
      pq.push({nums[i], i});
    }

    int result = 0;

    for (int i = 1; i <= right; i++)
    {
      auto p = pq.top();
      pq.pop();

      // If the current index is greater than or equal to left, add the
      // value to the answer.
      if (i >= left)
      {
        result = (result + p.first) % M;
      }

      // If index is less than the last index, increment it and add its
      // value
      if (p.second < n - 1)
      {
        p.second++;
        p.first += nums[p.second];
        pq.push(p);
      }
    }
    return result;
  }
};

class Solution
{
public:
  int rangeSum(vector<int> &nums, int n, int left, int right)
  {
    vector<int> subs;
    int MOD = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
      long long sum = nums[i];
      subs.push_back(sum);
      for (int j = i + 1; j < n; j++)
      {
        sum += nums[j];
        subs.push_back(sum);
      }
    }

    sort(subs.begin(), subs.end());

    long long sum = 0;
    for (int i = left - 1; i < right; i++)
      sum = (sum + subs[i]) % MOD;

    return sum % MOD;
  }
};