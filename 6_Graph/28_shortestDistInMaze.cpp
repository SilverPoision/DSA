class Solution
{
public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                   pair<int, int> di)
  {
    if (s.first == di.first && s.second == di.second)
      return 0;
    if (grid[s.first][s.second] == 0)
      return -1;

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[s.first][s.second] = 0;
    q.push({{s.first, s.second}, 0});
    int rowN[] = {-1, 0, 1, 0};
    int colN[] = {0, 1, 0, -1};

    while (!q.empty())
    {
      int i = q.front().first.first;
      int j = q.front().first.second;
      int d = q.front().second;
      q.pop();

      for (int ind = 0; ind < 4; ind++)
      {
        int row = i + rowN[ind];
        int col = j + colN[ind];

        if (row >= 0 && col >= 0 && row < n && col < m && grid[row][col] == 1 && d + 1 < dist[row][col])
        {
          dist[row][col] = d + 1;
          if (row == di.first && col == di.second)
            return d + 1;
          q.push({{row, col}, d + 1});
        }
      }
    }
    return -1;
  }
};