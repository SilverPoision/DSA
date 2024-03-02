class Solution
{
public:
  // more optimal
  // https://leetcode.com/problems/stone-game-vi/description/
  int stoneGameVI(vector<int> &av, vector<int> &bv)
  {
    int n = av.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
      arr.push_back({av[i] + bv[i], i});
    }

    sort(arr.begin(), arr.end());

    int alice = 0, bob = 0;
    bool turn = true;

    for (int i = 0; i < n; i++)
    {
      int max = arr[n - 1 - i].first;
      int ind = arr[n - 1 - i].second;

      if (turn)
      {
        alice += av[ind];
      }
      else
      {
        bob += bv[ind];
      }
      turn = !turn;
    }

    if (alice == bob)
      return 0;
    return alice > bob ? 1 : -1;
  }
};

class Solution
{
public:
  int stoneGameVI(vector<int> &av, vector<int> &bv)
  {
    int n = av.size();
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
      q.push({av[i] + bv[i], i});
    }

    int alice = 0, bob = 0;
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
      int max = q.top().first;
      int ind = q.top().second;
      q.pop();
      if (flag)
      {
        alice += av[ind];
      }
      else
      {
        bob += bv[ind];
      }
      flag = !flag;
    }

    if (alice == bob)
      return 0;
    return alice > bob ? 1 : -1;
  }
};