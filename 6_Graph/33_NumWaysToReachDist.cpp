#define ll long long

class Solution
{
public:
  int countPaths(int n, vector<vector<int>> &roads)
  {
    unordered_map<int, vector<pair<int, int>>> m;
    for (auto it : roads)
    {
      m[it[0]].push_back({it[1], it[2]});
      m[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});
    vector<ll> ways(n, 0);
    vector<ll> dist(n, LLONG_MAX);
    ways[0] = 1;
    dist[0] = 0;
    ll mod = (int)(1e9 + 7);

    while (!q.empty())
    {
      ll wt = q.top().first;
      ll node = q.top().second;
      q.pop();

      for (auto it : m[node])
      {
        ll v = it.first;
        ll w = it.second;

        if (dist[v] > w + wt)
        {
          dist[v] = w + wt;
          q.push({dist[v], v});
          ways[v] = ways[node];
        }
        else if (dist[v] == w + wt)
        {
          ways[v] = (ways[node] + ways[v]) % mod;
        }
      }
    }
    return ways[n - 1] % mod;
  }
};