class Solution
{
public:
  // https://leetcode.com/problems/find-common-characters/?envType=daily-question&envId=2024-06-05
  vector<string> commonChars(vector<string> &words)
  {
    int n = words.size();
    unordered_map<int, unordered_map<char, int>> hash;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < words[i].size(); j++)
      {
        hash[i][words[i][j]]++;
      }
    }

    vector<string> ans;

    for (int j = 0; j < words[0].size(); j++)
    {
      bool flag = true;
      for (int k = 1; k < n; k++)
      {
        if (hash[k][words[0][j]] <= 0)
        {
          flag = false;
        }
        hash[k][words[0][j]]--;
      }

      if (flag)
      {
        string ch = "";
        ch.push_back(words[0][j]);
        ans.push_back(ch);
      }
    }

    return ans;
  }
};

// optimal
class Solution
{
public:
  vector<string> commonChars(vector<string> &words)
  {
    vector<int> finalFreq(26, 1e9);

    for (auto it : words)
    {
      vector<int> currFreq(26, 0);
      for (auto i : it)
        currFreq[i - 'a']++;

      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        finalFreq[ch - 'a'] = min(finalFreq[ch - 'a'], currFreq[ch - 'a']);
      }
    }

    vector<string> ans;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      while (finalFreq[ch - 'a']--)
      {
        ans.push_back(string(1, ch));
      }
    }

    return ans;
  }
};