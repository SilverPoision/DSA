class Solution
{
public:
  // https://leetcode.com/problems/maximum-total-importance-of-roads/?envType=daily-question&envId=2024-06-28
  long long maximumImportance(int n, vector<vector<int>> &roads)
  {
    vector<int> count(n, 0);

    for (auto it : roads)
    {
      ++count[it[0]];
      ++count[it[1]];
    }

    sort(count.begin(), count.end());

    long long ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      ans = ans + (long long)n * count[i];
      n--;
    }

    return ans;
  }
};

class Solution
{
public:
  long long maximumImportance(int n, vector<vector<int>> &roads)
  {
    unordered_map<int, int> hash;

    for (auto it : roads)
    {
      int u = it[0];
      int v = it[1];
      hash[u]++;
      hash[v]++;
    }

    priority_queue<pair<long long, int>> pq;
    for (auto it : hash)
      pq.push({it.second, it.first});
    long long ans = 0;

    while (!pq.empty())
    {
      int maxEle = pq.top().second;
      long long maxi = pq.top().first;
      pq.pop();

      ans = ans + ((long long)n * maxi);
      n--;
    }

    return ans;
  }
};