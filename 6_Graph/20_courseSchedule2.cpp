class Solution
{
public:
  vector<int> findOrder(int n, vector<vector<int>> &pre)
  {
    map<int, vector<int>> adj;
    for (auto it : pre)
    {
      adj[it[0]].push_back(it[1]);
    }

    vector<int> ans;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
      for (auto it : adj[i])
      {
        indegree[it]++;
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

    if (ans.size() == n)
    {
      reverse(ans.begin(), ans.end());
      return ans;
    }
    else
    {
      return vector<int>();
    }
  }
};