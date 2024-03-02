class Solution
{
public:
  bool checkValidString(string s)
  {
    int leftMin = 0, leftMax = 0;

    for (auto it : s)
    {
      if (it == '(')
      {
        leftMin++;
        leftMax++;
      }
      else if (it == ')')
      {
        leftMin--;
        leftMax--;
      }
      else if (it == '*')
      {
        leftMax++;
        leftMin--;
      }

      if (leftMax < 0)
        return false;

      if (leftMin < 0)
        leftMin = 0;
    }

    return leftMin == 0;
  }
};