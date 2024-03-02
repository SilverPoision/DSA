class Solution
{
public:
  vector<int> row = {1, -1, 0, 0};
  vector<int> col = {0, 0, 1, -1};
  void dfs(vector<vector<int>> &image, int i, int j, int newColor)
  {
    int n = image.size();
    int m = image[0].size();
    int ini = image[i][j];
    image[i][j] = newColor;
    for (int ind = 0; ind < 4; ind++)
    {
      int nRow = i + row[ind];
      int nCol = j + col[ind];

      if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == ini && image[nRow][nCol] != newColor)
      {
        dfs(image, nRow, nCol, newColor);
      }
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    vector<vector<int>> ans = image;
    dfs(ans, sr, sc, newColor);
    return ans;
  }
};