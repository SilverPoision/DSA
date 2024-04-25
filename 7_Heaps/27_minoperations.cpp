class Solution
{
public:
  // https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii
  typedef long long int ll;
  int minOperations(vector<int> &nums, int k)
  {

    priority_queue<ll, vector<ll>, greater<ll>> q;

    for (auto it : nums)
      q.push(it);

    int cnt = 0;

    while (!q.empty())
    {
      if (q.top() >= k)
        return cnt;

      ll a = q.top();
      q.pop();
      ll b = q.top();
      q.pop();

      cnt++;
      q.push((a << 1) + b);
    }

    return cnt;
  }
};