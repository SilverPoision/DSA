class Solution
{
public:
  // https://leetcode.com/problems/minimum-height-trees/?envType=daily-question&envId=2024-04-23
  // https://www.youtube.com/watch?v=tJAwo2hgMU8
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
  {
    if (n == 1)
    {
      return {0};
    }

    vector<int> res;
    vector<int> indegree(n, 0);

    unordered_map<int, vector<int>> adj;

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      adj[u].push_back(v);
      adj[v].push_back(u);

      indegree[u]++;
      indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 1)
        q.push(i);
    }

    while (n > 2)
    {
      int s = q.size();
      n -= s;
      while (s--)
      {
        int fr = q.front();
        q.pop();

        for (auto it : adj[fr])
        {
          indegree[it]--;
          if (indegree[it] == 1)
          {
            q.push(it);
          }
        }
      }
    }

    while (!q.empty())
    {
      res.push_back(q.front());
      q.pop();
    }

    return res;
  }
};