class Solution
{
public:
  bool checkValid(string s)
  {
    int open = 0;
    for (auto it : s)
    {
      if (it == '(')
        open++;
      else if (it == ')' && open-- == 0)
        return false;
    }

    return open == 0;
  }

  vector<string> removeInvalidParentheses(string s)
  {
    unordered_map<string, bool> hash;
    queue<string> q;
    q.push(s);
    hash[s] = 1;
    vector<string> ans;
    bool found = false;

    while (!q.empty())
    {
      string front = q.front();
      q.pop();

      if (checkValid(front))
      {
        ans.push_back(front);
        found = true;
      }
      /*
     this will ensure that the bfs stops here because
     lets assuem it found the string at 2 deleteion then why we need
     valid strs with 3 delettiona and all the strings with 2
     deletions are already in the queue if they are valid they
     will be pushed in ans
     Brilliant solution
      */
      if (found)
        continue;

      for (int i = 0; i < front.size(); i++)
      {
        if (front[i] != ')' && front[i] != '(')
          continue;

        string t = front.substr(0, i) + front.substr(i + 1);
        if (hash[t] != 1)
        {
          q.push(t);
          hash[t] = 1;
        }
      }
    }

    return ans;
  }
};

// TLE
class Solution
{
public:
  void f(int i, string &s, unordered_set<string> &hash, string out, int open, int req)
  {
    if (req < 0)
      return;
    if (i == s.size())
    {
      if (open == 0 && out.size() > 1 && (hash.size() == 0 || out.size() == (*hash.begin()).size()))
      {
        hash.insert(out);
      }
      return;
    }

    if (s[i] != '(' && s[i] != ')')
    {
      f(i + 1, s, hash, out + s[i], open, req);
      return;
    }

    f(i + 1, s, hash, out, open, req - 1);

    if (s[i] == '(')
      open++;
    else if (open > 0 && s[i] == ')')
      open--;
    else if (open == 0 && s[i] == ')')
    {
      f(i + 1, s, hash, out, open, req - 1);
      return;
    }

    f(i + 1, s, hash, out + s[i], open, req);
  }
  vector<string> removeInvalidParentheses(string s)
  {
    int open = 0, req = 0;
    for (auto it : s)
    {
      if (it == '(')
        open++;
      else if (open > 0 && it == ')')
        open--;
      else
        req++;
    }
    req += open;

    unordered_set<string> hash;
    f(0, s, hash, "", 0, req);
    if (hash.size() == 0)
    {
      string temp = "";
      for (auto it : s)
      {
        if (it != '(' && it != ')')
          temp += it;
      }
      return {temp};
    }
    vector<string> ans(hash.begin(), hash.end());
    return ans;
  }
};