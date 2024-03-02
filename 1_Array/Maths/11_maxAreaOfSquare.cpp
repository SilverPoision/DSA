class Solution
{
public:
  // https://www.youtube.com/watch?v=6c6Mnh0WU5k
  // https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
  int maximizeSquareHoleArea(int n, int m, vector<int> &h, vector<int> &v)
  {
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());

    int cnt = 1;
    int hMax = 1;
    int vMax = 1;

    for (int i = 1; i < h.size(); i++)
    {
      if (h[i - 1] + 1 == h[i])
        cnt++;
      else
        cnt = 1;
      hMax = max(hMax, cnt);
    }
    cnt = 1;
    for (int i = 1; i < v.size(); i++)
    {
      if (v[i - 1] + 1 == v[i])
        cnt++;
      else
        cnt = 1;
      vMax = max(vMax, cnt);
    }

    int len = min(hMax, vMax) + 1;

    return len * len;
  }
};