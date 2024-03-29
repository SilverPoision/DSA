class Solution
{
public:
  // https://www.youtube.com/watch?v=rYh-Kkbzsnw
  // https://leetcode.com/problems/task-scheduler/description/
  int leastInterval(vector<char> &tasks, int n)
  {
    vector<int> freq(26, 0);
    priority_queue<int> q;
    int time = 0;

    for (auto it : tasks)
    {
      freq[it - 'A']++;
    }

    for (auto it : freq)
    {
      if (it > 0)
        q.push(it);
    }

    while (!q.empty())
    {
      vector<int> temp;
      for (int i = 1; i <= n + 1; i++)
      {
        if (!q.empty())
        {
          int f = q.top();
          q.pop();
          f--;
          temp.push_back(f);
        }
      }

      for (auto it : temp)
      {
        if (it > 0)
          q.push(it);
      }

      if (q.empty())
      {
        time += temp.size();
      }
      else
      {
        time += n + 1;
      }
    }

    return time;
  }
};

///

class Solution
{
public:
  // https://www.youtube.com/watch?v=rYh-Kkbzsnw
  int leastInterval(vector<char> &tasks, int n)
  {
    vector<int> freq(26, 0);

    for (auto it : tasks)
    {
      freq[it - 'A']++;
    }
    sort(freq.begin(), freq.end());

    int chunk = freq[25] - 1;
    int idolSpots = chunk * n;

    for (int i = 24; i >= 0; i--)
    {
      idolSpots -= min(chunk, freq[i]);
    }

    if (idolSpots > 0)
      return tasks.size() + idolSpots;
    return tasks.size();
  }
};