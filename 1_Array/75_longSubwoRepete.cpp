class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int n = s.size();
    int i = 0, j = 0;
    int maxi = 0;

    map<char, int> hash;

    while (i < n && j < n)
    {
      char c = s[j];
      if (hash.find(c) == hash.end())
      {
        hash[c] = j;
        maxi = max(maxi, (j - i + 1));
      }
      else
      {
        int temp = hash[c] + 1;
        for (int k = i; k <= hash[c]; k++)
        {
          hash.erase(s[k]);
        }
        i = temp;
        hash[c] = j;
      }
      j++;
    }

    return maxi;
  }
};