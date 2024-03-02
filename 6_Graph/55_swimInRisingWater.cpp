class Solution
{
public:
  // https://leetcode.com/problems/swim-in-rising-water/
  int swimInWater(vector<vector<int>> &grid)
  {
    int n = grid.size();
    typedef pair<int, int> p;
    priority_queue<pair<int, p>, vector<pair<int, p>>, greater<pair<int, p>>> q;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    q.push({grid[0][0], {0, 0}});
    int t = grid[0][0];
    dist[0][0] = grid[0][0];

    vector<int> r = {0, 0, -1, 1};
    vector<int> c = {-1, 1, 0, 0};

    while (!q.empty())
    {
      int x = q.top().second.first;
      int y = q.top().second.second;
      int time = q.top().first;
      q.pop();

      t = max(t, time);

      for (int i = 0; i < 4; i++)
      {
        int row = x + r[i];
        int col = y + c[i];

        if (row >= 0 && col >= 0 && row < n && col < n)
        {
          if (dist[row][col] > max(t, grid[row][col]))
          {
            dist[row][col] = max(t, grid[row][col]);
            q.push({dist[row][col], {row, col}});
          }
        }
      }
    }

    return dist[n - 1][n - 1];
  }
};

// DSU
// this can also be used https://ideone.com/yqfrm7
class DisJointSet
{
public:
  vector<int> parent, rank, size;
  DisJointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int findUPar(int node)
  {
    if (node == parent[node])
      return node;

    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u, int v)
  {
    int ulp_v = findUPar(v);
    int ulp_u = findUPar(u);

    if (ulp_v == ulp_u)
      return;
    if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    else if (rank[ulp_v] > rank[ulp_u])
    {
      parent[ulp_u] = ulp_v;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
  void unionBySize(int u, int v)
  {
    int ulp_v = findUPar(v);
    int ulp_u = findUPar(u);

    if (ulp_v == ulp_u)
      return;
    if (size[ulp_v] < size[ulp_u])
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
    else
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
  }
};

class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {
    int n = grid.size();
    if (n == 1)
      return 0;

    DisJointSet dsu(n * n);
    unordered_map<int, pair<int, int>> hash;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        hash[grid[i][j]] = {i, j};
      }
    }

    int t = 0;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    while (dsu.findUPar(0) != dsu.findUPar(n * n - 1))
    {
      auto node = hash[t];
      int r = node.first;
      int c = node.second;

      for (int i = 0; i < 4; i++)
      {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] <= t)
        {
          dsu.unionByRank(r * n + c, nr * n + nc);
        }
      }

      t++;
    }

    return t - 1;
  }
};