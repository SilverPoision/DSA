class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    // XOR to find differing bits
    int xorResult = start ^ goal;
    int count = 0;
    // Brian Kernighans algorithm to count 1s
    while (xorResult)
    {
      xorResult &= (xorResult - 1); // Clear the lowest set bit
      count++;
    }
    return count;
  }
};

class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    int cnt = 0, i = 0;

    while (i < 32)
    {
      if ((start & (1 << i)) != (goal & (1 << i)))
        cnt++;
      i++;
    }

    return cnt;
  }
};