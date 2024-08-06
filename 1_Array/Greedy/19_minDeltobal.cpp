class Solution
{
public:
  // https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/?envType=daily-question&envId=2024-07-30
  int minimumDeletions(string s)
  {
    int n = s.size();
    if (n == 1)
      return 0;
    int a = 0;
    for (auto it : s)
      a += it == 'a' ? 1 : 0;
    if (a == 0 || a == n)
      return 0;

    int cnt = 0;
    int mini = n + 1;
    for (int i = 0; i < n; i++)
    {
      int leftB = ((i)-cnt);
      int rightA = a - cnt;

      mini = min(mini, leftB + rightA);
      if (s[i] == 'a')
        cnt++;
    }
    int leftB = ((n)-cnt);
    int rightA = a - cnt;

    mini = min(mini, leftB + rightA);

    return mini;
  }
};