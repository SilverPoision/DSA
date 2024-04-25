// Heap
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    priority_queue<pair<int, int>> max;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
      while (!max.empty() && max.top().second <= i - k)
      {
        max.pop();
      }
      max.push({nums[i], i});
      if (i >= k - 1)
      {
        ans.push_back(max.top().first);
      }
    }
    return ans;
  }
};

// Optimal
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    deque<pair<int, int>> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
      while (!dq.empty() && dq.front().second <= (i - k))
      {
        dq.pop_front();
      }
      while (!dq.empty() && dq.back().first < nums[i])
      {
        dq.pop_back();
      }
      dq.push_back({nums[i], i});
      if (i >= k - 1)
      {
        ans.push_back(dq.front().first);
      }
    }
    return ans;
  }
};