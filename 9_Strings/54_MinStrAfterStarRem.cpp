typedef pair<char, int> pci;

class Compare
{
public:
  bool operator()(pci &a, pci &b)
  {
    if (a.first == b.first)
    {
      return a.second < b.second;
    }
    return a.first > b.first;
  }
};

class Solution
{
public:
  // https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/
  string clearStars(string s)
  {
    priority_queue<pci, vector<pci>, Compare> pq;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '*')
      {
        s[pq.top().second] = '_';
        pq.pop();
      }
      else
      {
        pq.push({s[i], i});
      }
    }

    string ans = "";

    for (auto it : s)
    {
      if (it != '_' && it != '*')
        ans.push_back(it);
    }

    return ans;
  }
};