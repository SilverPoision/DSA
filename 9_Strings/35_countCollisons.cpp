class Solution
{
public:
  // https://leetcode.com/problems/count-collisions-on-a-road/
  int countCollisions(string d)
  {
    int r = 0, s = 0;

    int col = 0;

    for (auto it : d)
    {
      if (it == 'L')
      {
        if (r > 0)
        {
          col += 2 + r - 1;
          r = 0;
          s++;
        }
        else if (s > 0)
        {
          col++;
        }
      }
      else if (it == 'R')
      {
        r++;
      }
      else
      {
        if (r > 0)
        {
          col += r;
          r = 0;
        }
        s++;
      }
    }

    return col;
  }
};