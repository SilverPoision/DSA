class Solution
{
public:
  // https://leetcode.com/problems/single-number-ii/description/
  int singleNumber(vector<int> &nums)
  {
    int ones = 0; // this will contain no that are repeated one time
    int twos = 0; // this will contain no that are repeted twice

    for (auto it : nums)
    {
      ones = (ones ^ it) & (~twos);
      twos = (twos ^ it) & (~ones);
    }

    return ones;
  }
};