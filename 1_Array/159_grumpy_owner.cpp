class Solution
{
public:
  // https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21
  int maxSatisfied(vector<int> &c, vector<int> &g, int m)
  {
    int n = c.size();
    int j = 0;
    int sum = 0, maxi = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      if (g[i] == 0)
        ans += c[i];
      sum += g[i] == 1 ? c[i] : 0;

      if (i - j + 1 > m)
      {
        sum -= g[j] == 1 ? c[j] : 0;
        j++;
      }

      maxi = max(maxi, sum);
    }

    return ans + maxi;
  }
};