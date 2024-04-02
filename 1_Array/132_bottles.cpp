class Solution
{
public:
  // https://leetcode.com/problems/water-bottles-ii/
  int maxBottlesDrunk(int numBottles, int numExchange)
  {
    int ans = numBottles;
    numBottles = 0;
    int emptyBottles = ans;

    while (numExchange <= emptyBottles)
    {
      ans++;
      emptyBottles -= numExchange;
      numExchange++;
      emptyBottles++;
    }

    return ans;
  }
};