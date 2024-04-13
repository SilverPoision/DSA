class Solution
{
public:
  // https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/description/
  string getSmallestString(string s, int k)
  {
    int n = s.size();

    vector<char> c;
    for (char ch = 'a'; ch <= 'z'; ch++)
      c.push_back(ch);

    for (int i = 0; i < n; i++)
    {

      if (k == 0)
        return s;

      char it = s[i];
      if (it == 'a')
        continue;

      int req = 26 - (it - 'a');

      if (req < 13)
      {
        s[i] = c[(((it - 'a') + min(req, k)) % 26) == 0 ? 0 : (((it - 'a') - min(req, k)) % 26)];
        k -= min(req, k);
      }
      else
      {
        s[i] = c[(abs((it - 'a') - min(it - 'a', k)) % 26)];
        k -= min(it - 'a', k);
      }
      if (k == 0)
        return s;
    }

    return s;
  }
};