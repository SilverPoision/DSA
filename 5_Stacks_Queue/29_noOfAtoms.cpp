class Solution
{
public:
  // https://www.youtube.com/watch?v=NYLmQI0GkeM
  //  https://leetcode.com/problems/number-of-atoms/?envType=daily-question&envId=2024-07-14
  string countOfAtoms(string f)
  {
    map<string, int> hash;

    stack<pair<string, int>> st;

    int i = 0, n = f.size();
    while (i < n)
    {
      if (f[i] == '(')
        st.push({string(1, f[i++]), 0});
      else if (f[i] >= 'A' && f[i] <= 'Z')
      {
        string temp = string(1, f[i]);
        int j = i + 1;
        while (j < n && f[j] >= 'a' && f[j] <= 'z')
          temp += f[j++];

        int num = 0;
        while (j < n && f[j] >= '0' && f[j] <= '9')
        {
          num = (num * 10) + f[j++] - '0';
        }
        st.push({temp, num == 0 ? 1 : num});
        i = j;
      }
      else if (f[i] == ')' && i + 1 < n && f[i + 1] >= '1' && f[i + 1] <= '9')
      {
        int num = 0;
        int j = i + 1;
        while (j < n && f[j] >= '0' && f[j] <= '9')
        {
          num = (num * 10) + f[j++] - '0';
        }
        stack<pair<string, int>> ts;

        while (!st.empty() && st.top().first != "(")
        {
          auto t = st.top();
          st.pop();
          ts.push({t.first, t.second * num});
        }
        st.pop();

        while (!ts.empty())
        {
          st.push(ts.top());
          ts.pop();
        }

        i = j;
      }
      else
        i++;
    }

    while (!st.empty())
    {
      auto t = st.top();
      st.pop();
      if (t.first == "(")
        continue;

      hash[t.first] += t.second;
    }

    string ans = "";

    for (auto it : hash)
      ans += it.first + (it.second > 1 ? to_string(it.second) : "");

    return ans;
  }
};