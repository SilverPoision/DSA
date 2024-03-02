class KthLargest
{
public:
  int k = 0;
  priority_queue<int, vector<int>, greater<int>> mini;
  KthLargest(int k, vector<int> &nums)
  {
    this->k = k;
    auto endPointer = nums.begin() + min(k, (int)nums.size());
    mini = priority_queue<int, vector<int>, greater<int>>(nums.begin(), endPointer);
    for (int i = k; i < nums.size(); i++)
    {
      mini.push(nums[i]);
      mini.pop();
    }
  }

  int add(int val)
  {
    mini.push(val);
    if (mini.size() > k)
    {
      mini.pop();
    }

    return mini.top();
  }
};
