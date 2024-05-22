class Solution
{
public:
  // https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2024-05-09
  long long maximumHappinessSum(vector<int> &h, int k)
  {
    sort(h.begin(), h.end());

    long long i = 0, ans = 0;

    while (k--)
    {
      ans += h.back() - i > 0 ? h.back() - i : 0;
      i++;
      h.pop_back();
    }

    return ans;
  }
};