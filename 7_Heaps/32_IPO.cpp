class Solution
{
public:
  int findMaximizedCapital(int k, int w, vector<int> &p, vector<int> &c)
  {
    int n = p.size();
    vector<pair<int, int>> t;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
      t.push_back({c[i], p[i]});
    }

    sort(t.begin(), t.end());

    int i = 0;

    while (k > 0)
    {
      while (i < n && t[i].first <= w)
      {
        pq.push(t[i].second);
        i++;
      }

      if (pq.empty())
        return w;

      w += pq.top();
      pq.pop();
      k--;
    }

    return w;
  }
};