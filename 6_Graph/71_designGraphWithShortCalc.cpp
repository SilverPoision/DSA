class Graph
{
public:
  int n;
  vector<vector<int>> adj;
  Graph(int n, vector<vector<int>> &edges)
  {
    this->n = n;
    adj.resize(n, vector<int>(n, 1e9));

    for (auto it : edges)
    {
      adj[it[0]][it[1]] = it[2];
    }

    for (int i = 0; i < n; i++)
      adj[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
      }
    }
  }

  void addEdge(vector<int> edge)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        adj[i][j] = min(adj[i][j], adj[i][edge[0]] + adj[edge[1]][j] + edge[2]);
      }
    }
  }

  int shortestPath(int node1, int node2)
  {
    return adj[node1][node2] == 1e9 ? -1 : adj[node1][node2];
  }
};

//=================

class Graph
{
public:
  int n;
  typedef pair<int, int> p;
  unordered_map<int, vector<p>> adj;
  Graph(int n, vector<vector<int>> &edges)
  {
    this->n = n;
    ;
    for (auto it : edges)
    {
      adj[it[0]].push_back({it[1], it[2]});
    }
  }

  void addEdge(vector<int> edge)
  {
    adj[edge[0]].push_back({edge[1], edge[2]});
  }

  int shortestPath(int node1, int node2)
  {
    priority_queue<p, vector<p>, greater<p>> q;
    q.push({0, node1});

    vector<int> dist(n, 1e9);
    dist[node1] = 0;

    while (!q.empty())
    {
      auto [w, u] = q.top();
      q.pop();

      // if (dist[u] != 1e9) continue;

      for (auto [v, wt] : adj[u])
      {
        if (dist[v] > w + wt)
        {
          dist[v] = w + wt;
          q.push({dist[v], v});
        }
      }
    }

    return dist[node2] == 1e9 ? -1 : dist[node2];
  }
};
