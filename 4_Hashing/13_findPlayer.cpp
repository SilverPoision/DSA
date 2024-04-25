class Solution
{
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches)
  {
    map<int, pair<int, int>> hash;
    for (auto it : matches)
    {
      hash[it[0]].first++;
      hash[it[1]].second++;
    }
    vector<vector<int>> ans(2);

    for (auto it : hash)
    {
      if (it.second.first > 0 && it.second.second == 0)
        ans[0].push_back(it.first);
      else if (it.second.second == 1)
        ans[1].push_back(it.first);
    }

    return ans;
  }
};

class Solution
{
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches)
  {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int present[100001] = {0};
    int losses[100001] = {0};
    vector<vector<int>> res(2);

    for (auto &it : matches)
    {
      int winner = it[0], loser = it[1];
      present[winner] = 1;
      present[loser] = 1;
      losses[loser]++;
    }

    for (int i = 1; i < 100001; i++)
    {
      if (!present[i])
        continue;

      if (losses[i] == 0)
        res[0].push_back(i);

      else if (losses[i] == 1)
        res[1].push_back(i);
    }
    return res;
  }
};