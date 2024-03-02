class Solution
{
public:
  string countAndSay(int n)
  {
    if (n == 1)
      return "1";
    if (n == 2)
      return "11";

    string s = "11";
    for (int i = 3; i <= n; i++)
    {
      string t = "";
      s += '&';
      int c = 1;
      for (int j = 1; j < s.size(); j++)
      {
        if (s[j - 1] != s[j])
        {
          t += to_string(c);
          t += s[j - 1];
          c = 1;
        }
        else
        {
          c++;
        }
      }
      s = t;
    }

    return s;
  }
};

// My
#include <bits/stdc++.h>

vector<pair<int, int>> numToPair(string num)
{
  vector<pair<int, int>> ans;
  int n = num.size();

  int freq = 1;
  for (int i = 1; i < n; i++)
  {
    if (num[i] == num[i - 1])
    {
      freq++;
    }
    else
    {
      ans.push_back({freq, int(num[i - 1] - '0')});
      freq = 1;
    }
  }

  ans.push_back({freq, int(num[n - 1] - '0')});

  return ans;
}

string pairToStr(vector<pair<int, int>> ans)
{
  string st = "";

  for (auto it : ans)
  {
    st += to_string(it.first) + to_string(it.second);
  }

  return st;
}

string lookAndSaySequence(int n)
{
  // Write your code here.
  if (n == 1)
    return "1";
  string s = to_string(n);
  vector<pair<int, int>> ans = numToPair("1");
  string st = pairToStr(ans);

  for (int i = 2; i < n; i++)
  {
    ans = numToPair(st);
    st = pairToStr(ans);
  }

  return st;
}