class Solution
{
public:
  vector<int> topo(int v, vector<int> adj[])
  {
    vector<int> indegree(v);
    for (int i = 0; i < v; i++)
    {
      for (auto j : adj[i])
      {
        indegree[j]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
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
    return ans;
  }
  string findOrder(string dict[], int N, int K)
  {
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
      string s1 = dict[i];
      string s2 = dict[i + 1];

      int len = min(s1.size(), s2.size());
      for (int j = 0; j < len; j++)
      {
        if (s1[j] != s2[j])
        {
          adj[s1[j] - 'a'].push_back(s2[j] - 'a');
          break;
        }
      }
    }

    vector<int> ans = topo(K, adj);
    string s = "";
    for (auto it : ans)
    {
      s = s + char(it + 'a');
    }

    return s;
  }
};