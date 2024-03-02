class Solution
{
public:
  // https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
  // https://www.youtube.com/watch?v=VA-90dTfIps
  typedef long long ll;
  long long largestSquareArea(vector<vector<int>> &b, vector<vector<int>> &t)
  {
    int n = b.size();

    ll area = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        ll minX = max(b[i][0], b[j][0]);
        ll maxX = min(t[i][0], t[j][0]);
        ll minY = max(b[i][1], b[j][1]);
        ll maxY = min(t[i][1], t[j][1]);

        if (minX < maxX && minY < maxY)
        {
          ll s = min(maxX - minX, maxY - minY);
          area = max(area, s * s);
        }
      }
    }

    return area;
  }
};