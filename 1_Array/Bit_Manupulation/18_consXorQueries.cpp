class Solution
{
public:
  vector<int> constructList(int q, vector<vector<int>> &qu)
  {
    vector<int> ans;

    int x = 0;

    for (int i = qu.size() - 1; i >= 0; i--)
    {
      if (qu[i][0] == 0)
      {
        ans.push_back(qu[i][1] ^ x);
      }
      else
      {
        x ^= qu[i][1];
      }
    }

    ans.push_back(x);

    sort(ans.begin(), ans.end());
    return ans;
  }
};
