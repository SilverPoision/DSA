class Solution
{
public:
  int findDiff(unordered_map<char, int> &hash)
  {
    int mf = -1e9;
    int lf = 1e9;

    for (auto it : hash)
    {
      mf = max(mf, it.second);

      if (it.second > 0)
      {
        lf = min(lf, it.second);
      }
    }

    return mf - lf;
  }
  int beautySum(string s)
  {
    int res = 0;

    for (int i = 0; i < s.size(); i++)
    {
      unordered_map<char, int> hash;
      for (int j = i; j < s.size(); j++)
      {
        hash[s[j]]++;

        int ans = findDiff(hash);
        res += ans;
      }
    }

    return res;
  }
};