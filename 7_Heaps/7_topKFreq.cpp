class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    priority_queue<pair<int, int>> max;
    map<int, int> hash;

    for (auto it : nums)
    {
      hash[it]++;
    }

    for (auto it : hash)
    {
      max.push({it.second, it.first});
    }

    vector<int> ans;

    while (k && !max.empty())
    {
      ans.push_back(max.top().second);
      max.pop();
      k--;
    }

    return ans;
  }
};