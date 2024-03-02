class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    // When you feel like you want to check the array from both ends then think of prefix sum like in this problem
    // Also can be solved with atmost approach
    map<int, int> m;
    int sum = 0;
    int cnt = 0;

    for (auto it : nums)
    {
      sum += it;

      if (sum == goal)
        cnt++;

      if (m.find(sum - goal) != m.end())
      {
        cnt += m[sum - goal];
      }

      m[sum]++;
    }

    return cnt;
  }
};