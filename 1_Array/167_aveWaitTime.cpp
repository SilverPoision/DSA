class Solution
{
public:
  // https://leetcode.com/problems/average-waiting-time/?envType=daily-question&envId=2024-07-09
  double averageWaitingTime(vector<vector<int>> &customers)
  {
    int time = 0;
    double wtime = 0;

    for (auto it : customers)
    {
      time = max(it[0], time) + it[1];
      wtime += time - it[0];
    }

    return wtime / (double)customers.size();
  }
};