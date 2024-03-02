class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int cnt = 0;
    int i = 0;
    int c[3] = {0, 0, 0};

    for (int j = 0; j < s.size(); j++)
    {
      c[s[j] - 'a']++;

      while (c[0] && c[1] && c[2])
      {
        --c[s[i++] - 'a'];
      }

      cnt += i;
    }

    return cnt;
  }
};

class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int cnt = 0;
    int a = -1, b = -1, c = -1;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == 'a')
        a = i;
      else if (s[i] == 'b')
        b = i;
      else if (s[i] == 'c')
        c = i;

      if (i > 1)
      {
        cnt += min(a, min(b, c)) + 1;
      }
    }

    return cnt;
  }
};