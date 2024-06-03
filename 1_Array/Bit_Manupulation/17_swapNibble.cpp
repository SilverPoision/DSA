class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1
  int swapNibbles(int n)
  {
    return (n & 0b00001111) << 4 | (n & 0b11110000) >> 4;
  }
};