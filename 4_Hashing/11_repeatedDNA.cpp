class Solution
{
public:
  // https://leetcode.com/problems/repeated-dna-sequences/
  vector<string> findRepeatedDnaSequences(string s)
  {
    set<string> res;
    unordered_map<string, bool> hash;

    int i = 0;
    int j = 9;

    while (j < s.size())
    {
      string temp = s.substr(i, j - i + 1);

      if (hash.find(temp) != hash.end())
      {
        res.insert(temp);
      }

      hash[s.substr(i, j - i + 1)] = true;
      i++;
      j++;
    }

    vector<string> ans(res.begin(), res.end());

    return ans;
  }
};