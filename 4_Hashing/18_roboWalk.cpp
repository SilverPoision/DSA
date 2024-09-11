class Solution
{
public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
  {
    unordered_set<long> obstacleSet;
    for (const auto &obs : obstacles)
    {
      obstacleSet.insert(static_cast<long>(obs[0]) * 100000 + obs[1]);
    }

    vector<int> directions = {0, 1, 0, -1, 0};
    int x = 0, y = 0, d = 0;
    int maxDist = 0;

    for (int cmd : commands)
    {
      if (cmd == -1)
      {
        d = (d + 1) % 4;
      }
      else if (cmd == -2)
      {
        d = (d + 3) % 4;
      }
      else
      {
        for (int k = 0; k < cmd; ++k)
        {
          int newX = x + directions[d];
          int newY = y + directions[d + 1];
          if (obstacleSet.find(static_cast<long>(newX) * 100000 + newY) == obstacleSet.end())
          {
            x = newX;
            y = newY;
            maxDist = max(maxDist, x * x + y * y);
          }
          else
          {
            break;
          }
        }
      }
    }

    return maxDist;
  }
};

//
class Solution
{
public:
  int robotSim(vector<int> &c, vector<vector<int>> &ob)
  {
    map<pair<int, int>, bool> hash;

    for (auto it : ob)
    {
      hash[{it[0], it[1]}] = true;
    }

    long long x = 0, y = 0, i = 0;
    int dir = 0;
    vector<vector<long long>> m = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int ans = 0;

    while (i < c.size())
    {
      cout << dir;
      if (c[i] == -2)
      {
        if (dir == 0)
          dir = 4;
        dir--;
      }
      else if (c[i] == -1)
      {
        dir++;
        dir = dir % 4;
      }
      else
      {
        int k = c[i];
        while (hash.find({x + m[dir][0], y + m[dir][1]}) ==
                   hash.end() &&
               k--)
        {
          x = x + m[dir][0];
          y = y + m[dir][1];
        }
      }
      ans = max(ans, (int)((x * x) + (y * y)));
      i++;
    }

    return ans;
  }
};