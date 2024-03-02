class Solution
{
public:
  int minimumMultiplications(vector<int> &arr, int start, int end)
  {
    queue<pair<int, int>> q;
    q.push({0, start});
    vector<int> dist(100000, 1e9);
    // dist[start] = 0;

    while (!q.empty())
    {
      int node = q.front().second;
      int step = q.front().first;
      q.pop();

      if (node == end)
        return step;

      for (auto it : arr)
      {
        int newNode = ((it * node) % 100000);
        if (dist[newNode] > step + 1)
        {
          dist[newNode] = step + 1;
          q.push({step + 1, newNode});
        }
      }
    }

    return -1;
  }
};