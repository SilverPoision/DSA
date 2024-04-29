// Graph
class Solution
{
public:
  typedef vector<int> v;
  int cntMin(int i, int k, int n)
  {
    int dist = abs(i - k);
    int wraparound = n - dist;

    return min(dist, wraparound);
  }
  int findRotateSteps(string ring, string key)
  {
    int n = ring.size();
    int m = key.size();

    unordered_map<char, vector<int>> hash;

    for (int i = 0; i < n; i++)
    {
      hash[ring[i]].push_back(i);
    }

    priority_queue<v, vector<v>, greater<v>> pq;
    pq.push({0, 0, 0});
    unordered_map<string, bool> seen;
    int totalSteps = 0;

    while (!pq.empty())
    {
      auto v = pq.top();
      pq.pop();

      int ringIdx = v[1];
      int keyIdx = v[2];
      totalSteps = v[0];

      if (keyIdx == m)
        break;

      string c = to_string(ringIdx) + '-' + to_string(keyIdx);
      if (seen.find(c) != seen.end())
        continue;
      seen[c] = true;

      for (auto nextIdx : hash[key[keyIdx]])
      {
        pq.push({totalSteps + cntMin(ringIdx, nextIdx, n), nextIdx, keyIdx + 1});
      }
    }

    return totalSteps + m;
  }
};

// DP

class Solution
{
public:
  int cntMin(int i, int k, string &ring)
  {
    int dist = abs(i - k);
    int wraparound = ring.size() - dist;

    return min(dist, wraparound);
  }
  int solve(int i, int j, string &ring, string &key, vector<vector<int>> &dp)
  {
    if (i == key.size())
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int res = 1e9;
    for (int k = 0; k < ring.size(); k++)
    {
      if (ring[k] == key[i])
      {
        int cntStep = 1 + cntMin(j, k, ring);
        res = min(res, cntStep + solve(i + 1, k, ring, key, dp));
      }
    }
    return dp[i][j] = res;
  }
  int findRotateSteps(string ring, string key)
  {
    int n = ring.size();
    vector<vector<int>> dp(101, vector<int>(101, -1));

    return solve(0, 0, ring, key, dp);
  }
};

// Tab
class Solution
{
public:
  int cntMin(int i, int k, string &ring)
  {
    int dist = abs(i - k);
    int wraparound = ring.size() - dist;

    return min(dist, wraparound);
  }
  int findRotateSteps(string ring, string key)
  {
    int n = ring.size();
    vector<vector<int>> dp(110, vector<int>(110, 0));

    for (int i = key.size() - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 0; j--)
      {
        int res = 1e9;
        for (int k = 0; k < ring.size(); k++)
        {
          if (ring[k] == key[i])
          {
            int cntStep = 1 + cntMin(j, k, ring);
            res =
                min(res, cntStep + dp[i + 1][k]);
          }
        }
        dp[i][j] = res;
      }
    }

    return dp[0][0];
  }
};

// S.O
class Solution
{
public:
  int cntMin(int i, int k, string &ring)
  {
    int dist = abs(i - k);
    int wraparound = ring.size() - dist;

    return min(dist, wraparound);
  }
  int findRotateSteps(string ring, string key)
  {
    int n = ring.size();
    vector<int> prev(102, 0), curr(102, 0);

    for (int i = key.size() - 1; i >= 0; i--)
    {
      for (int j = 0; j < n; j++)
      {
        int res = 1e9;
        for (int k = 0; k < ring.size(); k++)
        {
          if (ring[k] == key[i])
          {
            int cntStep = 1 + cntMin(j, k, ring);
            res =
                min(res, cntStep + prev[k]);
          }
        }
        curr[j] = res;
      }
      prev = curr;
    }

    return curr[0];
  }
};

// MY DP
class Solution
{
public:
  int solve(int i, int j, string &ring, string &key, int cost, vector<vector<vector<int>>> &dp, int n)
  {
    if (i == key.size())
      return 0;

    if (cost > n)
      return 1e9;

    if (dp[i][j][cost] != -1)
      return dp[i][j][cost];

    if (ring[j] == key[i])
    {
      return cost + 1 + solve(i + 1, j, ring, key, 0, dp, n);
    }
    int antiClock = solve(i, j - 1 < 0 ? n - 1 : j - 1, ring, key, cost + 1, dp, n);
    int clock = solve(i, j + 1 < n ? j + 1 : 0, ring, key, cost + 1, dp, n);

    return dp[i][j][cost] = min(clock, antiClock);
  }
  int findRotateSteps(string ring, string key)
  {
    int n = ring.size();
    vector<vector<vector<int>>> dp(110, vector<vector<int>>(110, vector<int>(110, -1)));

    return solve(0, 0, ring, key, 0, dp, n);
  }
};

class Solution
{
public:
  int solve(int i, int j, string &ring, string &key, vector<vector<int>> &dp,
            int n, int cost)
  {
    if (i == key.size())
      return 0;

    if (cost > n * n)
      return 1e9;

    if (dp[i][j] != -1)
      return dp[i][j];

    int cnt = 1e9;
    if (ring[j] == key[i])
    {
      cnt = 1 + solve(i + 1, j, ring, key, dp, n, 0);
    }

    int minus = j - 1 < 0 ? n - 1 : j - 1;
    int plus = j + 1 < n ? j + 1 : 0;

    int antiClock = 1 + solve(i, minus, ring, key, dp, n, cost + 1);
    int clock = 1 + solve(i, plus, ring, key, dp, n, cost + 1);

    return dp[i][j] = min({cnt, clock, antiClock});
  }
  int findRotateSteps(string ring, string key)
  {
    int n = ring.size();
    vector<vector<int>> dp(101, vector<int>(101, -1));

    return solve(0, 0, ring, key, dp, n, 0);
  }
};