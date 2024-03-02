class Solution
{
public:
  int leastInterval(vector<char> &tasks, int k)
  {
    priority_queue<int> pq;
    deque<pair<int, int>> q;

    map<char, int> m;

    for (auto it : tasks)
    {
      m[it]++;
    }

    for (auto it : m)
    {
      pq.push(it.second);
    }

    int time = 0;

    while (!pq.empty() || !q.empty())
    {
      time++;
      if (!pq.empty())
      {
        int top = pq.top() - 1;
        pq.pop();

        if (top > 0)
          q.push_back({top, time + k});
      }

      if (!q.empty())
      {
        if (q.front().second == time)
        {
          pq.push(q.front().first);
          q.pop_front();
        }
      }
    }

    return time;
  }
};