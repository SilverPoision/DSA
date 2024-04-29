class Solution
{
public:
  // https://leetcode.com/problems/open-the-lock/solutions/5057116/faster-lesser-detailed-explaination-bfs-step-by-step-explaination-python-java-c/
  string addOne(string s, int i)
  {
    if (s[i] == '9')
    {
      s[i] = '0';
      return s;
    }
    else
    {
      s[i]++;
      return s;
    }
  }
  string subOne(string s, int i)
  {
    if (s[i] == '0')
    {
      s[i] = '9';
      return s;
    }
    else
    {
      s[i]--;
      return s;
    }
  }
  int openLock(vector<string> &d, string target)
  {
    queue<string> q;
    q.push("0000");

    unordered_map<string, bool> hash;
    for (auto it : d)
      hash[it] = true;
    int cnt = 0;

    while (!q.empty())
    {
      int s = q.size();
      while (s--)
      {
        string node = q.front();
        q.pop();

        if (hash[node])
          continue;

        if (node == target)
          return cnt;

        hash[node] = true;

        for (int i = 0; i < 4; i++)
        {
          q.push(addOne(node, i));
          q.push(subOne(node, i));
        }
      }
      cnt++;
    }

    return -1;
  }
};