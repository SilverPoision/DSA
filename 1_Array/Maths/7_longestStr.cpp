class Solution
{
public:
  // https://leetcode.com/problems/construct-the-longest-new-string/description/
  int longestString(int x, int y, int z)
  {
    int cnt = 0;

    if (x > y)
    {
      cnt += y * 2;
      cnt += (y + 1) * 2;
      cnt += z * 2;
    }
    else if (y > x)
    {
      cnt += x * 2;
      cnt += (x + 1) * 2;
      cnt += z * 2;
    }
    else
    {
      cnt += x * 2;
      cnt += (x) * 2;
      cnt += z * 2;
    }

    return cnt;
  }
};