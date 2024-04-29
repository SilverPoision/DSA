class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1
  vector<int> sr = {0, 1, 0, -1};
  vector<int> sc = {1, 0, -1, 0};
  vector<int> FindExitPoint(int n, int m, vector<vector<int>> &mat)
  {
    // Code here
    int curI = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
      auto f = q.front();
      q.pop();

      int i = f.first;
      int j = f.second;

      if (mat[i][j] == 1)
      {
        curI = (curI + 1) % 4;
        mat[i][j] = 0;
      }
      if (i + sr[curI] >= n || i + sr[curI] < 0 || j + sc[curI] >= m || j + sc[curI] < 0)
        return {i, j};
      q.push({i + sr[curI], j + sc[curI]});
    }

    return {};
  }
};