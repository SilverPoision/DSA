class Solution
{
public:
  int cc(char c) { return c - 'a'; }
  long long minimumCost(string s, string t, vector<char> &o, vector<char> &c,
                        vector<int> &cost)
  {
    int n = c.size();
    vector<vector<int>> adj(26, vector<int>(26, 1e9));

    for (int i = 0; i < n; i++)
    {
      adj[cc(o[i])][cc(c[i])] = min(cost[i], adj[cc(o[i])][cc(c[i])]);
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
      adj[cc(i)][cc(i)] = 0;
    }

    for (char k = 'a'; k <= 'z'; k++)
    {
      for (char i = 'a'; i <= 'z'; i++)
      {
        for (char j = 'a'; j <= 'z'; j++)
        {
          adj[cc(i)][cc(j)] = min(adj[cc(i)][cc(j)], adj[cc(i)][cc(k)] + adj[cc(k)][cc(j)]);
        }
      }
    }

    long long int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if (adj[cc(s[i])][cc(t[i])] == 1e9)
        return -1;
      ans = ans + adj[cc(s[i])][cc(t[i])];
    }

    return ans;
  }
};

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