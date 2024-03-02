class Solution
{
public:
  string frequencySort(string s)
  {
    unordered_map<char, int> hash;
    priority_queue<pair<int, char>> pq;

    for (auto it : s)
    {
      hash[it]++;
    }

    for (auto it : hash)
    {
      pq.push({it.second, it.first});
    }

    string ans = "";

    while (!pq.empty())
    {
      auto top = pq.top();
      pq.pop();
      for (int i = 0; i < top.first; i++)
        ans += top.second;
    }

    return ans;
  }
};