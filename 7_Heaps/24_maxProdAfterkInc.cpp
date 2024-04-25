class Solution
{
public:
  int maximumProduct(vector<int> &nums, int k)
  {
    int mod = 1e9 + 7;
    priority_queue<int, vector<int>, greater<int>> q;

    for (auto it : nums)
      q.push(it);

    while (k--)
    {
      int top = q.top();
      q.pop();
      q.push(++top);
    }

    long long ans = 1;
    while (!q.empty())
    {
      ans = (ans * q.top()) % mod;
      q.pop();
    }

    return ans % mod;
  }
};