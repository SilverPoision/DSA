class Solution
{
public:
  // https://leetcode.com/problems/find-all-groups-of-farmland/
  pair<int, int> dfs(int i, int j, int n, int m, vector<vector<int>> &land)
  {
    if (i >= n || i < 0 || j >= m || j < 0 ||
        land[i][j] == 0)
      return {-1, -1};

    land[i][j] = 0;
    if (i == n - 1 && j == m - 1)
    {
      return {i, j};
    }

    pair<int, int> maxi = {i, j};

    maxi = max({maxi, dfs(i + 1, j, n, m, land),
                dfs(i, j + 1, n, m, land)});

    return maxi;
  }
  vector<vector<int>> findFarmland(vector<vector<int>> &land)
  {
    int n = land.size();
    int m = land[0].size();

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (land[i][j] == 1)
        {
          auto [r, c] = dfs(i, j, n, m, land);
          ans.push_back({i, j, r, c});
        }
      }
    }

    return ans;
  }
};