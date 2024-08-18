class Solution
{
public:
  // https://leetcode.com/problems/count-the-number-of-good-nodes/
  int ans = 0;
  int solve(int i, unordered_map<int, vector<int>> &adj, int par)
  {
    int ini = -1;
    bool f = true;
    int cnt = 0;

    for (auto it : adj[i])
    {
      if (it == par)
        continue;
      int s = solve(it, adj, i);
      if (ini == -1)
        ini = s;
      else
      {
        if (ini != s)
          f = false;
      }
      cnt += s;
    }

    if (f)
      ans++;

    return cnt + 1;
  }
  int countGoodNodes(vector<vector<int>> &edges)
  {
    unordered_map<int, vector<int>> adj;
    for (auto it : edges)
    {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }

    solve(0, adj, -1);

    return ans;
  }
};