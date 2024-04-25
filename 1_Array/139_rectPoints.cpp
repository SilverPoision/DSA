class Solution
{
public:
  // https://leetcode.com/problems/minimum-rectangles-to-cover-points/
  int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
  {
    sort(points.begin(), points.end());

    int past = points[0][0];
    int ans = 1;
    for (int i = 1; i < points.size(); i++)
    {
      if (points[i][0] - past > w)
      {
        ans++;
        past = points[i][0];
      }
    }

    return ans;
  }
};