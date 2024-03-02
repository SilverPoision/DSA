class Solution
{
public:
  void f(int i, string &s, set<string> &word, vector<string> &out, vector<string> &temp)
  {
    if (i == s.size())
    {
      string sr = "";
      for (auto it : temp)
      {
        sr += it + " ";
      }
      out.push_back(sr.substr(0, sr.length() - 1));
    }

    string tempo;
    for (int k = i; k < s.size(); k++)
    {
      tempo += s[k];
      if (word.find(tempo) != word.end())
      {
        temp.push_back(tempo);
        f(k + 1, s, word, out, temp);
        temp.pop_back();
      }
    }
  }
  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    set<string> st;
    vector<string> temp;
    for (auto it : wordDict)
      st.insert(it);
    vector<string> out;
    f(0, s, st, out, temp);
    return out;
  }
};