class Solution
{
public:
  int rangeBitwiseAnd(int left, int right)
  {

    int shiftCount = 0;

    while (left != right)
    {

      left = (left >> 1);
      right = (right >> 1);

      shiftCount++;
    }

    return left << shiftCount;
  }
};

class Solution
{
public:
  int rangeBitwiseAnd(int left, int right)
  {

    while (right > left)
    {
      right = right & right - 1;
    }

    return right;
  }
};

class Solution
{
public:
  // tle
  int rangeBitwiseAnd(int left, int right)
  {

    int ans = left;
    int i = 1;

    while ((pow(2, i) - 1) < left)
    {
      i++;
    }

    while (left <= min((int)(pow(2, i) - 1), right))
    {
      ans &= left++;
    }

    if (left > right)
      return ans;

    while (pow(2, i) <= right)
    {
      ans &= (int)pow(2, i);
      i++;
    }

    return ans;
  }
};