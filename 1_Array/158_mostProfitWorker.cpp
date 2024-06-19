class Solution
{
public:
  // https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18
  int maxProfitAssignment(vector<int> &d, vector<int> &p, vector<int> &w)
  {
    vector<pair<int, int>> sorted;
    int n = d.size();

    for (int i = 0; i < n; i++)
    {
      sorted.push_back({d[i], p[i]});
    }

    sort(sorted.begin(), sorted.end());
    sort(w.begin(), w.end());

    int ans = 0;
    int best = 0, j = 0;

    for (auto it : w)
    {
      while (j < n && it >= sorted[j].first)
      {
        best = max(best, sorted[j].second);
        j++;
      }
      ans += best;
    }

    return ans;
  }
};