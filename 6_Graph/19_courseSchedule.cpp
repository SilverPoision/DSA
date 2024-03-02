class Solution
{
public:
  bool detectCycle(int i, map<int, vector<int>> &adj, map<int, bool> &visited, map<int, bool> &dfsVis)
  {
    visited[i] = true;
    dfsVis[i] = true;

    for (auto it : adj[i])
    {
      if (!visited[it])
      {
        if (detectCycle(it, adj, visited, dfsVis))
          return true;
      }
      else if (dfsVis[it])
      {
        return true;
      }
    }
    dfsVis[i] = false;
    return false;
  }

  bool canFinish(int numCourses, vector<vector<int>> &preq)
  {
    map<int, vector<int>> adj;
    for (auto it : preq)
    {
      adj[it[0]].push_back(it[1]);
    }

    map<int, bool> visited, dfsVis;
    for (int i = 0; i < numCourses; i++)
    {
      if (!visited[i])
      {
        if (detectCycle(i, adj, visited, dfsVis))
        {
          return false;
        }
      }
    }
    return true;
  }
};