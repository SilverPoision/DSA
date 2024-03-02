class Solution
{
public:
  int findCity(int n, int m, vector<vector<int>> &edges, int dt)
  {
    vector<vector<int>> cost(n, vector<int>(n, 1e9));

    for (auto it : edges)
    {
      cost[it[0]][it[1]] = it[2];
      cost[it[1]][it[0]] = it[2];
    }

    for (int i = 0; i < n; i++)
    {
      cost[i][i] = 0;
    }

    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
      }
    }

    int city = -1, cityMin = 1e9, cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt = 0;
      for (int j = 0; j < n; j++)
      {
        if (cost[i][j] <= dt)
          cnt++;
      }
      if (cityMin >= cnt)
      {
        cityMin = cnt;
        city = i;
      }
    }

    return city;
  }
};