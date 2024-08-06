class Solution
{
public:
  // https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/?envType=daily-question&envId=2024-08-06
  int minimumPushes(string word)
  {
    vector<int> hash(26, 0);

    for (auto it : word)
      hash[it - 'a']++;

    sort(hash.begin(), hash.end(), greater<int>());

    int cnt = 1;
    int ans = 0;
    int cc = 0;

    for (auto it : hash)
    {
      if (cc == 8)
      {
        cc = 0;
        cnt++;
      }
      ans += it * cnt;
      cc++;
    }

    return ans;
  }
};