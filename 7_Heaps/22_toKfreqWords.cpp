class Compare
{
public:
  bool operator()(pair<int, string> a, pair<int, string> b)
  {
    if (a.first == b.first)
    {
      return a.second > b.second; // for acending order
    }
    return a.first < b.first; // for decending order
  }
};

class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    unordered_map<string, int> hash;
    for (auto it : words)
      hash[it]++;

    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;

    for (auto it : hash)
    {
      q.push({it.second, it.first});
    }

    vector<string> ans;
    while (ans.size() < k)
    {
      ans.push_back(q.top().second);
      q.pop();
    }

    return ans;
  }
};