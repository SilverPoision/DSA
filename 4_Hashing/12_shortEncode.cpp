class Solution
{
public:
  // https://leetcode.com/problems/short-encoding-of-words/
  int minimumLengthEncoding(vector<string> &words)
  {
    unordered_map<string, int> hash;
    for (auto it : words)
      hash[it]++;

    for (auto it : words)
    {
      string temp = "";
      for (int i = it.size() - 1; i > 0; i--)
      {
        temp = it[i] + temp;
        if (hash.find(temp) != hash.end())
        {
          hash.erase(temp);
        }
      }
    }

    int cnt = 0;
    for (auto it : hash)
    {
      cnt += it.first.size() + 1;
    }

    return cnt;
  }
};