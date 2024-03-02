class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {
    queue<int> q;
    vector<int> color(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++)
    {
      if (color[i] == -1)
      {
        q.push(i);
        color[i] = 0;

        while (!q.empty())
        {
          int front = q.front();
          q.pop();

          for (auto it : graph[front])
          {
            if (color[it] != -1)
            {
              if (color[front] == color[it])
              {
                return false;
              }
            }
            else
            {
              color[it] = color[front] == 1 ? 0 : 1;
              q.push(it);
            }
          }
        }
      }
    }
    return true;
  }
};