/*
391. Perfect Rectangle
Hard
743
108
Companies
Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.



Example 1:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.
*/

class Solution
{
public:
  bool isRectangleCover(vector<vector<int>> &rect)
  {
    map<pair<int, int>, int> m;

    for (auto it : rect)
    {
      m[{it[0], it[1]}]++;
      m[{it[2], it[3]}]++;
      m[{it[0], it[3]}]--;
      m[{it[2], it[1]}]--;
    }

    int corners = 0;
    for (auto it : m)
    {
      corners += abs(it.second);
    }

    return corners == 4;
  }
};