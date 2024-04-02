class Solution
{
public:
  // https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/description/
  string minimizeStringValue(string s)
  {
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> q;
    unordered_map<char, int> hash;

    int cnt = 0;

    for (auto it : s)
    {
      if (it == '?')
      {
        cnt++;
        continue;
      }
      hash[it]++;
    }

    for (auto [k, v] : hash)
    {
      q.push({v, k});
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
      if (hash.find(c) == hash.end())
      {
        q.push({0, c});
      }
    }

    string a = "";
    while (cnt--)
    {
      auto [f, c] = q.top();
      q.pop();
      a += c;
      q.push({f + 1, c});
    }

    sort(a.begin(), a.end());
    int k = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '?')
      {
        s[i] = a[k++];
      }
    }
    return s;
  }
};