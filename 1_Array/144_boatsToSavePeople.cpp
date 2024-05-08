class Solution
{
public:
  int numRescueBoats(vector<int> &p, int limit)
  {
    sort(p.begin(), p.end());

    int i = 0, j = p.size() - 1;

    int cnt = 0;

    while (i <= j)
    {
      if (p[i] + p[j] <= limit)
      {
        i++;
        j--;
        cnt++;
      }
      else
      {
        j--;
        cnt++;
      }
    }

    return cnt++;
  }
};

class Solution
{
public:
  int numRescueBoats(vector<int> &people, int limit)
  {
    multiset<int> p(people.begin(), people.end());

    int cnt = 0;

    while (!p.empty())
    {
      int sm = *p.begin();
      p.erase(p.begin());
      auto lb = p.upper_bound(limit - sm);
      if (lb != p.begin())
        p.erase(--lb);
      cnt++;
    }

    return cnt;
  }
};