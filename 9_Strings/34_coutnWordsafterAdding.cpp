class Solution
{
public:
  int wordCount(vector<string> &startWords, vector<string> &targetWords)
  {
    // generates hashes for startWords.
    unordered_set<int> vis;
    for (string s : startWords)
    {
      int hash = 0;
      for (int i = 0; i < s.size(); i++)
      {
        hash += (1 << (s[i] - 'a'));
      }
      vis.insert(hash);
    }

    // check each target Word
    int res = 0;
    for (string s : targetWords)
    {
      int hash = 0;
      // k is the index of character we remove
      for (int k = 0; k < s.size(); k++)
      {
        hash = 0;
        for (int i = 0; i < s.size(); i++)
        {
          if (i == k)
            continue;
          hash += (1 << (s[i] - 'a'));
        }
        if (vis.count(hash))
        {
          res++;
          break;
        }
      }
    }

    return res;
  }
};

class Solution
{
public:
  // tle
  int wordCount(vector<string> &sw, vector<string> &tw)
  {
    unordered_map<int, unordered_map<char, bool>> hash;

    int ans = 0;

    for (int i = 0; i < sw.size(); i++)
    {
      for (int j = 0; j < sw[i].size(); j++)
      {
        hash[i][sw[i][j]] = true;
      }
    }

    for (int i = 0; i < tw.size(); i++)
    {
      for (int j = 0; j < sw.size(); j++)
      {
        int cnt = 0;
        if (tw[i].size() == (sw[j].size() + 1))
        {
          for (int k = 0; k < tw[i].size(); k++)
          {
            if (!hash[j][tw[i][k]])
            {
              cnt++;
            }
          }
          if (cnt == 1)
          {
            ans++;
            break;
          }
        }
      }
    }

    return ans;
  }
};

// tle
class Solution
{
public:
  int wordCount(vector<string> &sw, vector<string> &tw)
  {
    unordered_map<int, int> twhash, swhash;

    int ans = 0;

    for (int i = 0; i < sw.size(); i++)
    {
      swhash[i] = 0;
      for (int j = 0; j < sw[i].size(); j++)
      {
        swhash[i] |= (1 << (sw[i][j] - 'a'));
      }
    }
    for (int i = 0; i < tw.size(); i++)
    {
      twhash[i] = 0;
      for (int j = 0; j < tw[i].size(); j++)
      {
        twhash[i] |= (1 << (tw[i][j] - 'a'));
      }
    }

    for (int i = 0; i < tw.size(); i++)
    {
      for (int j = 0; j < sw.size(); j++)
      {
        if (tw[i].size() == (sw[j].size() + 1))
        {
          int cnt = 0;
          int a = twhash[i];
          int b = swhash[j];
          int x = a ^ b;

          while (x)
          {
            x = x & (x - 1);
            cnt++;
          }
          if (cnt == 1)
          {
            ans++;
            break;
          }
        }
      }
    }

    return ans;
  }
};