class Solution
{
public:
  // https://leetcode.com/problems/minimum-cost-to-convert-string-i/
  void dijkstra(char ch, unordered_map<char, vector<pair<char, int>>> &hash, vector<int> &dist)
  {
    dist[ch - 'a'] = 0;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> q;
    q.push({0, ch});

    while (!q.empty())
    {
      auto f = q.top();
      char node = f.second;
      int w = f.first;
      q.pop();

      for (auto it : hash[node])
      {
        char v = it.first;
        int wt = it.second;

        int ind = v - 'a';

        if (wt + w < dist[ind])
        {
          dist[ind] = w + wt;
          q.push({dist[ind], v});
        }
      }
    }
  }
  long long minimumCost(string s, string t, vector<char> &o, vector<char> &c, vector<int> &cost)
  {
    int n = o.size();
    int m = s.size();
    unordered_map<char, vector<pair<char, int>>> hash;
    for (int i = 0; i < n; i++)
    {
      hash[o[i]].push_back({c[i], cost[i]});
    }

    vector<int> ma(26, 1e9);
    unordered_map<char, vector<int>> dist;

    set<char> charList;

    for (int i = 0; i < m; i++)
    {
      charList.insert(s[i]);
      charList.insert(t[i]);
    }

    for (char ch : charList)
    {
      dijkstra(ch, hash, ma);
      dist[ch] = ma;
      ma.assign(27, 1e9);
    }

    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
      int so = s[i];
      int tar = t[i];

      if (dist[so][tar - 'a'] == 1e9)
        return -1;

      sum += dist[so][tar - 'a'];
    }

    return sum;
  }
};