class Solution
{
public:
  // https://leetcode.com/problems/maximum-total-reward-using-operations-ii/
  int maxTotalReward(vector<int> &r)
  {
    bitset<50000> dp, mask;
    dp[0] = 1;
    sort(r.begin(), r.end());

    int maskID = 0;
    int closestSum = r.back() - 1;

    for (int i = 0; i + 1 < r.size(); i++)
    {
      if (r[i] > maskID)
      {
        while (maskID < r[i])
        {
          mask[maskID++] = true;
        }
        dp |= (dp & mask) << r[i];
      }
    }

    while (!dp[closestSum])
      --closestSum;

    return r.back() + closestSum;
  }
};