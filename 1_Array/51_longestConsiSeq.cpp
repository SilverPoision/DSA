class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> s;

    for (auto it : nums)
    {
      s.insert(it);
    }

    int longest = 0;
    for (auto it : nums)
    {
      if (s.find(it - 1) == s.end())
      {
        int x = it;
        int cnt = 1;
        while (s.find(x + 1) != s.end())
        {
          cnt++;
          x++;
        }
        longest = max(longest, cnt);
      }
    }

    return longest;
  }
};