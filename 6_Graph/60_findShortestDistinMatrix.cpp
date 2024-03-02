class Solution
{
public:
  // works
  const int INF = 1e9 + 10;
  int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads)
  {
    int n = specialRoads.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INF);

    for (int i = 0; i < n; i++)
    {
      dist[i] = abs(specialRoads[i][0] - start[0]) + abs(specialRoads[i][1] - start[1]) + specialRoads[i][4];
      pq.push({dist[i], i});
    }
    int res = abs(target[0] - start[0]) + abs(target[1] - start[1]);
    while (!pq.empty())
    {
      auto [total_dist, i] = pq.top();
      pq.pop();
      if (total_dist != dist[i]) // this is to discard changed items because they will be less ultimatley
        continue;
      res = min(res, total_dist + abs(specialRoads[i][2] - target[0]) + abs(specialRoads[i][3] - target[1]));
      for (int nxt = 0; nxt < n; nxt++)
      {
        int val = total_dist + abs(specialRoads[i][2] - specialRoads[nxt][0]) + abs(specialRoads[i][3] - specialRoads[nxt][1]) + specialRoads[nxt][4];
        if (val < dist[nxt])
        {
          dist[nxt] = val;
          pq.push({dist[nxt], nxt});
        }
      }
    }
    return res;
  }
};

class Solution
{
public:
  // not ralible and intutive
  int dp[402][402];
  int f(int i, vector<vector<int>> &v, int prev, int sx, int sy, int ex,
        int ey)
  {
    if (i == v.size())
    {
      if (prev == -1)
      {
        return (abs(sx - ex) + abs(sy - ey));
      }
      return (abs(v[prev][2] - ex) + abs(v[prev][3] - ey) + v[prev][4]);
    }

    if (dp[i][prev + 1] != -1)
      return dp[i][prev + 1];

    int notTake = f(i + 1, v, prev, sx, sy, ex, ey);
    int take = 1e9;
    if (prev == -1)
    {
      take = (abs(v[i][0] - sx) + abs(v[i][1] - sy)) +
             f(i + 1, v, i, sx, sy, ex, ey);
    }
    else
    {
      take = (abs(v[prev][2] - v[i][0]) + abs(v[prev][3] - v[i][1]) +
              v[prev][4]) +
             f(i + 1, v, i, sx, sy, ex, ey);
    }

    return dp[i][prev + 1] = min(take, notTake);
  }
  int minimumCost(vector<int> &start, vector<int> &target,
                  vector<vector<int>> &s)
  {
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> v = s;
    for (int i = 0; i < s.size(); i++)
    {
      v.push_back(s[i]);
    }
    return f(0, v, -1, start[0], start[1], target[0], target[1]);
  }
};

// mine works but takes long time
#define pii pair<int, int>

class Solution
{
public:
  void dijkstra(pii start, map<pii, vector<vector<int>>> &adj,
                vector<vector<int>> &dist,
                unordered_map<long int, int> &hash)
  {
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, start});

    while (!q.empty())
    {
      auto top = q.top();
      int cost = -top.first;
      pii node = top.second;
      q.pop();

      for (auto it : adj[node])
      {
        pii n = {it[0], it[1]};
        int c = it[2];

        if (c + cost < dist[hash[n.first]][hash[n.second]])
        {
          dist[hash[n.first]][hash[n.second]] = c + cost;
          // cout << "huwuw";
          q.push({-c - cost, n});
        }
      }
    }
  }
  int dist(pair<int, int> a, pair<int, int> b)
  {
    return (abs(a.first - b.first) + abs(a.second - b.second));
  }
  int minimumCost(vector<int> &s, vector<int> &target,
                  vector<vector<int>> &v)
  {

    // marking all the nodes
    pii start = {s[0], s[1]};
    pii end = {target[0], target[1]};

    // creating the adjacency matrix
    map<pii, vector<vector<int>>> adj;
    // dist between start to end
    adj[start].push_back({end.first, end.second, dist(start, end)});

    unordered_map<long int, int> hash;
    int cnt = 0;
    hash[start.first] = cnt++;
    hash[start.second] = cnt++;
    hash[end.first] = cnt++;
    hash[end.second] = cnt++;
    // adding all the special edges
    for (auto it : v)
    {
      pii a = {it[0], it[1]};
      pii b = {it[2], it[3]};
      hash[it[0]] = cnt++;
      hash[it[1]] = cnt++;
      hash[it[2]] = cnt++;
      hash[it[3]] = cnt++;
      adj[a].push_back({b.first, b.second, it[4]});
    }

    // adding all the crossedges
    for (int i = 0; i < v.size(); i++)
    {
      pii ai = {v[i][0], v[i][1]};
      pii bi = {v[i][2], v[i][3]};
      for (int j = i + 1; j < v.size(); j++)
      {
        pii aj = {v[j][0], v[j][1]};
        pii bj = {v[j][2], v[j][3]};
        adj[ai].push_back({bi.first, bi.second, dist(ai, bi)});
        adj[ai].push_back({bj.first, bj.second, dist(ai, bj)});
        adj[bi].push_back({ai.first, ai.second, dist(bi, ai)});
        adj[bi].push_back({aj.first, aj.second, dist(aj, bi)});
        adj[aj].push_back({bi.first, bi.second, dist(aj, bi)});
        adj[aj].push_back({bj.first, bj.second, dist(aj, bj)});
        adj[bj].push_back({ai.first, ai.second, dist(bj, ai)});
        adj[bj].push_back({aj.first, aj.second, dist(aj, bj)});
      }
    }
    // pushing all the nodes from start.
    for (auto it : v)
    {
      pii a = {it[0], it[1]};
      pii b = {it[2], it[3]};
      adj[start].push_back({a.first, a.second, dist(a, start)});
      adj[start].push_back({b.first, b.second, dist(b, start)});
    }
    // adding all the edges from v to end
    for (auto it : v)
    {
      pii a = {it[2], it[3]};
      adj[a].push_back({end.first, end.second, dist(a, end)});
    }

    vector<vector<int>> dist(cnt + 10, vector<int>(cnt + 10, 1e9));
    dist[hash[start.first]][hash[start.second]] = 0;
    dijkstra(start, adj, dist, hash);

    return dist[hash[end.first]][hash[end.second]];
  }
};