class Solution
{
public:
  // https://leetcode.com/problems/compare-version-numbers/submissions/1248465047/?envType=daily-question&envId=2024-05-03
  int compareVersion(string v1, string v2)
  {
    int n = v1.size();
    int m = v2.size();

    int i = 0, j = 0;

    while (i < n || j < m)
    {
      int vv1 = 0, vv2 = 0;

      while (i < n && v1[i] != '.')
      {
        vv1 = vv1 * 10 + (v1[i] - '0');
        i++;
      }
      i++;

      while (j < m && v2[j] != '.')
      {
        vv2 = vv2 * 10 + (v2[j] - '0');
        j++;
      }
      j++;

      if (vv1 > vv2)
        return 1;
      if (vv1 < vv2)
        return -1;
    }

    return 0;
  }
};