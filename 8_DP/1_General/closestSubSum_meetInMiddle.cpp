class Solution
{
public:
  vector<int> findAllSubSum(vector<int> &nums, int start, int end, int offset)
  {
    vector<int> res;
    int n = end - start + 1;

    for (int i = 0; i < (1 << n); i++)
    {
      int sum = 0;
      for (int bit = 0; bit < n; bit++)
      {
        if (i & (1 << bit))
        {
          sum += nums[bit + offset];
        }
      }
      res.push_back(sum);
    }

    return res;
  }
  int minAbsDifference(vector<int> &nums, int goal)
  {
    int n = nums.size();
    if (n == 1)
      return min(abs(goal), abs(nums[0] - goal));

    vector<int> left = findAllSubSum(nums, 0, n / 2 - 1, 0);
    vector<int> right = findAllSubSum(nums, n / 2, n - 1, n / 2);

    sort(right.begin(), right.end());

    int mini = abs(goal);
    for (int i = 0; i < left.size(); i++)
    {
      int lb = lower_bound(right.begin(), right.end(), goal - left[i]) - right.begin();

      if (lb > 0)
      {
        mini = min(mini, abs(goal - (left[i] + right[lb - 1])));
      }
      if (lb < right.size())
      {
        mini = min(mini, abs(goal - (left[i] + right[lb])));
      }
    }

    return mini;
  }
};