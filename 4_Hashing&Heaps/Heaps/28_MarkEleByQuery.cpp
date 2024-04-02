class Solution
{
public:
  // https://leetcode.com/problems/mark-elements-on-array-by-performing-queries/
  typedef pair<int, vector<int>> pv;
  vector<long long> unmarkedSumArray(vector<int> &nums,
                                     vector<vector<int>> &q)
  {
    int n = nums.size();

    map<int, vector<int>> hash;
    vector<long long> ans;
    priority_queue<pv, vector<pv>, greater<pv>> p;
    long long sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      hash[nums[i]].push_back(i);
      sum += nums[i];
    }

    for (auto [k, v] : hash)
    {
      p.push({k, v});
    }

    for (auto it : q)
    {
      int ind = it[0];
      int k = it[1];

      if (nums[ind] > 0)
      {
        sum -= nums[ind];
        nums[ind] = -nums[ind];
      }

      while (k && !p.empty())
      {
        auto [num, v] = p.top();
        p.pop();

        int size = v.size();

        int to = max(0, size - k);
        for (int i = size - 1; i >= to; i--)
        {
          int it = v[i];
          if (nums[it] > 0)
          {
            k--;
            sum -= nums[it];
            nums[it] = -nums[it];
          }
          v.pop_back();
        }

        if (v.size() > 0)
        {
          p.push({num, v});
        }
      }

      ans.push_back(sum);
    }

    return ans;
  }
};