class Solution
{
public:
  int f(int i, vector<int> &price, vector<vector<int>> &special, vector<int> &need, int n)
  {
    if (i == special.size())
    {
      int total = 0;
      for (int k = 0; k < n; k++)
      {
        total += need[k] * price[k];
      }
      return total;
    }

    int notTake = f(i + 1, price, special, need, n);

    vector<int> needs = need;

    int take = 1e9;
    bool takeFlag = true;
    for (int k = 0; k < n; k++)
    {
      if (needs[k] < special[i][k])
        takeFlag = false;
    }

    if (takeFlag)
    {
      for (int k = 0; k < n; k++)
      {
        needs[k] -= special[i][k];
      }
      take = special[i][n] + f(i, price, special, needs, n);
    }

    return min(take, notTake);
  }
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
  {
    map<vector<int>, int> mp; // vector, cost

    int n = price.size();
    // to remove the duplicate offers and keep the one with minimum price
    for (int i = 0; i < special.size(); i++)
    {
      auto temp = special[i];
      temp.pop_back();

      if (mp.find(temp) != mp.end())
      {
        mp[temp] = min(mp[temp], special[i][n]);
      }
      else
      {
        mp[temp] = special[i][n];
      }
    }

    // now insert these elements into the special matrix
    special.clear();

    for (auto it : mp)
    {
      auto temp = it.first;
      temp.push_back(it.second);
      special.push_back(temp);
    }
    int total = f(0, price, special, needs, n);

    return total;
  }
};