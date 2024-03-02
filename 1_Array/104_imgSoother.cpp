class Solution
{
public:
  // https://leetcode.com/problems/image-smoother/
  vector<vector<int>> imageSmoother(vector<vector<int>> &img)
  {
    int n = img.size();
    int m = img[0].size();

    vector<vector<int>> ans(n, vector<int>(m));

    vector<int> r = {1, -1, 0, 0, 1, -1, -1, 1};
    vector<int> c = {0, 0, 1, -1, 1, -1, 1, -1};

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int sum = img[i][j];
        int cnt = 1;
        for (int k = 0; k < 8; k++)
        {
          int row = i + r[k];
          int col = j + c[k];
          if (row >= 0 && col >= 0 && row < n && col < m)
          {
            cnt++;
            sum += img[row][col];
          }
        }
        ans[i][j] = sum / cnt;
      }
    }

    return ans;
  }
};