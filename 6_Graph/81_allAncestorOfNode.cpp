class Solution
{
public:
  // https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/?envType=daily-question&envId=2024-06-29
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
  {
    vector<vector<int>> ans(n), directChild(n);
    for (auto &e : edges)
    {
      directChild[e[0]].push_back(e[1]);
    }
    for (int i = 0; i < n; i++)
    {
      dfs(i, i, ans, directChild);
    }
    return ans;
  }

private:
  void dfs(int x, int curr, vector<vector<int>> &ans, vector<vector<int>> &directChild)
  {
    for (int ch : directChild[curr])
    {
      if (ans[ch].empty() || ans[ch].back() != x)
      {
        ans[ch].push_back(x);
        dfs(x, ch, ans, directChild);
      }
    }
  }
};

class Solution
{
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
  {
    unordered_map<int, vector<int>> indegree;
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      indegree[v].push_back(u);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
      set<int> s;
      queue<int> q;
      for (auto it : indegree[i])
        q.push(it);
      vector<bool> vis(n, false);

      while (!q.empty())
      {
        int front = q.front();
        q.pop();
        if (vis[front])
          continue;
        vis[front] = true;
        s.insert(front);

        for (auto it : indegree[front])
          q.push(it);
      }

      vector<int> temp(s.begin(), s.end());
      ans.push_back(temp);
    }

    return ans;
  }
};
