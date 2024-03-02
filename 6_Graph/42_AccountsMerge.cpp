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
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
  {
    int n = accounts.size();
    unordered_map<string, int> mapMailNode;
    DisJointSet ds(n);

    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < accounts[i].size(); j++)
      {
        string mail = accounts[i][j];
        if (mapMailNode.find(mail) == mapMailNode.end())
        {
          mapMailNode[mail] = i;
        }
        else
        {
          ds.unionByRank(i, mapMailNode[mail]);
        }
      }
    }

    vector<string> mapString[n];
    for (auto it : mapMailNode)
    {
      string mail = it.first;
      int node = it.second;
      int par = ds.findUPar(node);
      mapString[par].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
      if (mapString[i].size() == 0)
        continue;
      sort(mapString[i].begin(), mapString[i].end());
      vector<string> temp;
      temp.push_back(accounts[i][0]);
      for (auto it : mapString[i])
      {
        temp.push_back(it);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};
