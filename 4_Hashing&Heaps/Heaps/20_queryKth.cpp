class Solution
{
public:
  // https://leetcode.com/problems/query-kth-smallest-trimmed-number/
  // try doing it through radix sort
  void trimAndFindAns(vector<string> nums, vector<int> &q, vector<int> &ans)
  {
    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
      string temp = nums[i];
      string key = temp.substr(temp.size() - q[1]);
      pq.push({key, i});
    }

    int k = q[0];

    while (k > 1)
    {
      pq.pop();
      k--;
    }

    ans.push_back(pq.top().second);
  }
  vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &q)
  {
    vector<int> ans;

    for (auto it : q)
    {
      trimAndFindAns(nums, it, ans);
    }

    return ans;
  }
};

// more optimal
class Solution
{
public:
  typedef pair<string, int> pi;
  vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
  {
    vector<int> ans;
    int n = nums.size();
    for (auto &q : queries)
    {
      vector<pi> v;
      for (int i = 0; i < n; i++)
      {
        int t = q[1];
        int n1 = nums[i].size();
        string s = nums[i].substr(n1 - t);
        v.push_back({s, i});
      }
      sort(v.begin(), v.end());
      int k = q[0];
      ans.push_back(v[k - 1].second);
    }
    return ans;
  }
};