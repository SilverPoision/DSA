class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    int n = s.size(), m = g.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = n - 1, j = m - 1;

    int ans = 0;

    while (i >= 0 && j >= 0)
    {
      if (s[i] >= g[j])
      {
        ans++;
        i--;
        j--;
      }
      else
      {
        j--;
      }
    }

    return ans;
  }
};