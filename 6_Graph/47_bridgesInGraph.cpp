/*
1192. Critical Connections in a Network using tarzans algo
Hard
5.3K
171
Companies
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.



Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

While traversing adjacent nodes let ‘v’ of a particular node let ‘u’,
then 3 cases arise –

1. v is parent of u then,

    skip that iteration.

2. v is visited then,

    update the low of u i.e. low[u] = min( low[u] , disc[v]) this arises
    when a node can be visited by more than one node, but low is to keep
    track of the lowest possible time so we will update it.

3. v is not visited then,

    call the DFS to traverse ahead
    now update the low[u] = min( low[u], low[v] ) as we know v can’t be
    parent cause we have handled that case first.now check
    if ( low[v] > disc[u] ) i.e. the lowest possible to time
    to reach ‘v’ is greater than ‘u’ this means we can’t reach ‘v’
    without ‘u’ so the edge   u -> v is a bridge.
*/

// Bridge is an edges that if removed, it converts the graph into multiple components

class Solution
{
  int time = 1;

  void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[], vector<vector<int>> &res)
  {
    vis[node] = 1;
    low[node] = tin[node] = time;
    time++;

    for (auto it : adj[node])
    {
      if (it == parent)
        continue;
      if (!vis[it])
      {
        dfs(it, node, vis, tin, low, adj, res);
        low[node] = min(low[node], low[it]);

        if (low[it] > tin[node])
        {
          res.push_back({it, node});
        }
      }
      else
      {
        low[node] = min(low[node], tin[it]);
      }
    }
  }

public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
  {
    vector<int> adj[n];
    for (auto it : connections)
    {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    vector<int> tin(n), low(n);
    vector<vector<int>> res;
    dfs(0, -1, vis, tin, low, adj, res);

    return res;
  }
};