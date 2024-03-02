class Solution
{
public:
  bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &dfsvis, vector<int> &check)
  {
    vis[node] = 1;
    dfsvis[node] = 1;
    check[node] = 0;

    for (auto it : graph[node])
    {
      if (!vis[it])
      {
        if (dfs(it, graph, vis, dfsvis, check))
          return true;
      }
      else if (dfsvis[it])
      {
        return true;
      }
    }

    dfsvis[node] = 0;
    check[node] = 1;
    return false;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> dfsvis(n, 0);
    vector<int> check(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        dfs(i, graph, vis, dfsvis, check);
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (check[i] == 1)
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};

// BFS
class Solution
{
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (int i = 0; i < n; i++)
    {
      for (auto it2 : graph[i])
      {
        adj[it2].push_back(i); // reversing the edges so that we can start from the terminal and safe nodes
        indegree[i]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    vector<int> ans;
    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      ans.push_back(front);

      for (auto it : adj[front])
      {
        indegree[it]--;
        if (indegree[it] == 0)
        {
          q.push(it);
        }
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};