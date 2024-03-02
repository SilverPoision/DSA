class Solution
{
public:
  int MinimumEffort(vector<vector<int>> &h)
  {
    int n = h.size();
    int m = h[0].size();

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        q;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    q.push({0, {0, 0}});

    int r[] = {-1, 0, 1, 0};
    int c[] = {0, 1, 0, -1};

    while (!q.empty())
    {
      auto it = q.top();
      int i = it.second.first;
      int j = it.second.second;
      int d = it.first;
      q.pop();

      if (i == n - 1 && j == m - 1)
        return d;

      for (int k = 0; k < 4; k++)
      {
        int row = i + r[k];
        int col = j + c[k];

        if (row >= 0 && col >= 0 && row < n && col < m)
        {
          int differ = max(abs(h[i][j] - h[row][col]), d);

          if (differ < dist[row][col])
          {
            dist[row][col] = differ;
            q.push({differ, {row, col}});
          }
        }
      }
    }
    return 0;
  }
};