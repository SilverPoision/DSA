class Solution
{
public:
  // https://leetcode.com/problems/find-all-people-with-secret/?envType=daily-question&envId=2024-02-24
  // https://www.youtube.com/watch?v=hxEWwnJJKcY
  // solve this with union find
  typedef pair<int, int> P;
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson)
  {
    unordered_map<int, vector<P>> adj;

    for (auto it : meetings)
    {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, 0});
    q.push({0, firstPerson});

    vector<bool> vis(n, false);

    while (!q.empty())
    {
      auto [time, person] = q.top();
      q.pop();

      if (vis[person])
        continue;
      vis[person] = true;

      for (auto &[nextP, meetTime] : adj[person])
      {
        if (meetTime >= time && !vis[nextP])
        {
          q.push({meetTime, nextP});
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (vis[i])
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};

//==========================

class Solution
{
public:
  // sort of my
  typedef pair<int, int> P;
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson)
  {
    unordered_map<int, vector<P>> adj;

    for (auto it : meetings)
    {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> timeToKnow(n, 1e9);
    timeToKnow[0] = 0;
    timeToKnow[firstPerson] = 0;
    queue<P> q;
    q.push({0, 0});
    q.push({firstPerson, 0});

    while (!q.empty())
    {
      int person = q.front().first;
      int time = q.front().second;
      q.pop();

      for (auto &[nextP, meetTime] : adj[person])
      {
        if (meetTime >= time && timeToKnow[nextP] > meetTime)
        {
          timeToKnow[nextP] = meetTime;
          q.push({nextP, meetTime});
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (timeToKnow[i] != 1e9)
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};

//-----------------------------------

class Solution
{
public:
  // basic
  typedef pair<int, int> P;
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
  {
    map<int, vector<P>> timeMeets;

    for (auto it : meetings)
    {
      int p1 = it[0];
      int p2 = it[1];
      int time = it[2];

      timeMeets[time].push_back({p1, p2});
    }

    vector<bool> knows(n, false);
    knows[0] = true;
    knows[firstPerson] = true;

    for (auto it : timeMeets)
    {
      int time = it.first;
      vector<P> meets = it.second;

      unordered_map<int, vector<int>> adj;
      queue<int> q;
      unordered_set<int> alreadyAdded;

      for (auto &[person1, person2] : meets)
      {
        adj[person1].push_back(person2);
        adj[person2].push_back(person1);

        if (knows[person1] == true && alreadyAdded.find(person1) == alreadyAdded.end())
        {
          q.push(person1);
          alreadyAdded.insert(person1);
        }
        if (knows[person2] == true && alreadyAdded.find(person2) == alreadyAdded.end())
        {
          q.push(person2);
          alreadyAdded.insert(person2);
        }
      }

      while (!q.empty())
      {
        int p = q.front();
        q.pop();

        for (auto &nextP : adj[p])
        {
          if (knows[nextP] == false)
          {
            q.push(nextP);
            knows[nextP] = true;
          }
        }
      }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
      if (knows[i])
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};