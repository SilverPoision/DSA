class Solution
{
public:
  // https://leetcode.com/problems/magnetic-force-between-two-balls/?envType=daily-question&envId=2024-06-20
  bool check(vector<int> &p, int m, int mid)
  {
    int last = p[0];
    m--;
    for (int i = 1; i < p.size(); i++)
    {
      if (m == 0)
        return true;
      if (p[i] - last >= mid)
      {
        m--;
        last = p[i];
      }
    }

    return m == 0;
  }
  int maxDistance(vector<int> &p, int m)
  {
    sort(p.begin(), p.end());

    int l = 1, r = p.back() - p[0];
    int ans = 0;

    while (l <= r)
    {
      int mid = (l + r) / 2;

      if (check(p, m, mid))
      {
        ans = mid;
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    return ans;
  }
};