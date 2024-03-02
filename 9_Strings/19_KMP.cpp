class Solution
{
public:
  // most efficent string matching algo
  int strStr(string haystack, string needle)
  {
    // https://www.youtube.com/watch?v=JoF0Z7nVSrA
    int n = haystack.size();
    int m = needle.size();
    if (m == 0)
      return 0;

    vector<int> lps(m, 0);

    int prevLps = 0;
    int i = 1;

    while (i < m)
    {
      if (needle[prevLps] == needle[i])
      {
        lps[i] = prevLps + 1;
        prevLps++;
        i++;
      }
      else if (prevLps == 0)
      {
        lps[i] = 0;
        i++;
      }
      else
      {
        prevLps = lps[prevLps - 1];
      }
    }

    i = 0;
    int j = 0;

    while (i < n)
    {
      if (haystack[i] == needle[j])
      {
        i++;
        j++;
      }
      else if (j == 0)
      {
        i++;
      }
      else
      {
        j = lps[j - 1];
      }

      if (j == m)
      {
        return i - m;
      }
    }

    return -1;
  }
};