class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    priority_queue<int> max;
    int n = nums.size();
    for (auto it : nums)
    {
      max.push(it);
    }
    int ans;
    for (int i = 0; i < k; i++)
    {
      ans = max.top();
      max.pop();
    }
    return ans;
  }
};