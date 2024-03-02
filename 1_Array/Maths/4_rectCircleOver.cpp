class Solution
{
public:
  // https://leetcode.com/problems/circle-and-rectangle-overlapping/description/
  // https://www.youtube.com/watch?v=XIqPycfcRpw
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
  {
    int nearestX = max(x1, min(x2, xCenter));
    int nearestY = max(y1, min(y2, yCenter));

    int dx = nearestX - xCenter;
    int dy = nearestY - yCenter;

    int nd = dx * dx + dy * dy;

    return (radius * radius) >= nd;
  }
};