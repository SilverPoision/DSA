class Solution
{
public:
  bool isSafe(int node, bool graph[101][101], vector<int> &color, int n, int col)
  {
    for (int k = 0; k < n; k++)
    {
      if (node != k && graph[k][node] == 1 && color[k] == col)
      {
        return false;
      }
    }
    return true;
  }

  bool solve(int node, bool graph[101][101], vector<int> &color, int m, int n)
  {
    if (node == n)
      return true;

    for (int i = 1; i <= m; i++)
    {
      if (isSafe(node, graph, color, n, i))
      {
        color[node] = i;
        if (solve(node + 1, graph, color, m, n))
          return true;
        color[node] = 0;
      }
    }

    return false;
  }
  bool graphColoring(bool graph[101][101], int m, int n)
  {
    // your code here
    vector<int> color(n, 0);
    if (solve(0, graph, color, m, n) == true)
      return true;

    return false;
  }
};