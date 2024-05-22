class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1
  int minSteps(int d)
  {
    // code here
    int steps = 0, sum = 0;

    while (sum < d || abs(sum - d) % 2 != 0)
    {
      steps++;
      sum += steps;
    }

    return steps;
  }
};