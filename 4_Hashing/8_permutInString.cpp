class Solution
{
  // optimal
public:
  bool checkInclusion(string s1, string s2)
  {
    if (s2.size() < s1.size())
      return false;
    vector<int> s1Hash(26, 0);
    vector<int> s2Hash(26, 0);

    for (int i = 0; i < s1.size(); i++)
    {
      s1Hash[s1[i] - 'a']++;
      s2Hash[s2[i] - 'a']++;
    }

    int match = 0;
    for (int i = 0; i < 26; i++)
    {
      if (s1Hash[i] == s2Hash[i])
        match++;
    }

    int i = 0, j = s1.size();

    while (j < s2.size())
    {
      if (match == 26)
        return true;

      int ind = s2[j] - 'a';
      s2Hash[ind]++;

      if (s2Hash[ind] == s1Hash[ind])
        match++;
      else if (s2Hash[ind] == s1Hash[ind] + 1)
        match--;

      ind = s2[i] - 'a';
      s2Hash[ind]--;

      if (s2Hash[ind] == s1Hash[ind])
        match++;
      else if (s2Hash[ind] == s1Hash[ind] - 1)
        match--;
      i++;
      j++;
    }

    return match == 26;
  }
};

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    vector<int> sHash(26, 0);
    for (auto it : s1)
    {
      sHash[it - 'a']++;
    }

    for (int i = 0; i < s2.size(); i++)
    {
      int cnt = 0;
      vector<int> hash(26, 0);
      if (sHash[s2[i] - 'a'] > 0)
      {
        for (int j = i; j < s2.size(); j++)
        {
          if (sHash[s2[j] - 'a'] == 0 || hash[s2[j] - 'a'] >= sHash[s2[j] - 'a'])
            break;

          if (cnt == s1.size())
            return true;

          if (sHash[s2[j] - 'a'] > 0)
          {
            hash[s2[j] - 'a']++;
            cnt++;
          }
        }
        if (cnt == s1.size())
          return true;
      }
    }

    return false;
  }
};