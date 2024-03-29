class Solution
{
public:
  // https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
  int findMinArrowShots(vector<vector<int>> &points)
  {
    sort(
        points.begin(), points.end(),
        [](const vector<int> &a, const vector<int> &b)
        {
          if (a[1] == b[1])
            return a[0] < b[0];
          return a[1] < b[1];
        });

    int cnt = 1;
    long lastArrow = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
      int xS = points[i][0];
      int xE = points[i][1];
      if (xS > lastArrow)
      {
        cnt++;
        lastArrow = xE;
      }
    }

    return cnt;
  }
};

//
class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    sort(points.begin(), points.end());

    int cnt = 1;
    int lastArrow = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
      int xS = points[i][0];
      int xE = points[i][1];
      if (xS > lastArrow)
      {
        cnt++;
        lastArrow = xE;
      }
      else
      {
        lastArrow = min(xE, lastArrow);
      }
    }

    return cnt;
  }
};