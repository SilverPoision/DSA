#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Rectangle that is represented as a list [x1, y1, x2, y2],
where (x1, y1) is the coordinates of its top-left corner,
and (x2, y2) is the coordinates of its bottam-right corner.
Now two rectangles overlap if the area of their intersection
is positive.Two rectangles that only touch at the corner or
edges do not overlap.Check in O(1) Time complexity and O(1)
Space complexity that both rectangle overlap or not Asked in:
GoldmanSachs, Expedia, OLA

Example:

Input: rec1 = [0,8,8,0], rec2 = [5,5,15,0]

Solution:

x co-ordinate(top left point of one react) > x co-ordinate
(bottom roght poimt of other rect)
y co-ordinate(top left point of one react) < y co-ordinate
(bottom rigth poimt of other rect)
*/

class Solution
{
public:
  bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
  {
    struct points
    {
      int x, y;
    };

    points l1 = {rec1[0], rec1[1]};
    points l2 = {rec2[0], rec2[1]};
    points r1 = {rec1[2], rec1[3]};
    points r2 = {rec2[2], rec2[3]};

    if (l1.x == r1.x || l1.y == r1.y || l2.x == r2.x || l2.y == r2.y)
      return false;
    if (l2.y >= r1.y || l1.y >= r2.y)
      return false;
    if (l2.x >= r1.x || l1.x >= r2.x)
      return false;

    return true;
  }
};

/*
Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
*/