class Solution
{
public:
  // https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2024-07-12
  int ab(string &s, int points, string str)
  {
    stack<char> st;
    int i = s.size() - 1;
    int totPoints = 0;
    while (i >= 0)
    {
      if (s[i] == str[0] && !st.empty() && st.top() == str[1])
      {
        totPoints += points;
        st.pop();
      }
      else
        st.push(s[i]);
      i--;
    }

    s = "";
    while (!st.empty())
    {
      s.push_back(st.top());
      st.pop();
    }

    return totPoints;
  }

  int maximumGain(string s, int x, int y)
  {
    string s1 = "ab";
    string s2 = "ba";

    if (x < y)
    {
      swap(s1, s2);
      swap(x, y);
    }

    return ab(s, x, s1) + ab(s, y, s2);
  }
};