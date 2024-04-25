class Solution
{
public:
  // same approach just other way around\
  //https://leetcode.com/problems/furthest-building-you-can-reach/description/
  int furthestBuilding(vector<int> &h, int b, int l)
  {
    int n = h.size();
    priority_queue<int> pq;

    for (int i = 0; i < n - 1; i++)
    {
      int diff = h[i + 1] - h[i];

      if (diff <= 0)
      {
        continue;
      }

      b -= diff;
      pq.push(diff);

      if (b < 0)
      {
        if (l == 0)
          return i;
        l--;
        b += pq.top();
        pq.pop();
      }
    }

    return n - 1;
  }
};

class Solution
{
public:
  int furthestBuilding(vector<int> &h, int b, int l)
  {
    int n = h.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0;
    while (i < n - 1)
    {
      if (h[i + 1] <= h[i])
      {
        i++;
        continue;
      }

      int diff = h[i + 1] - h[i];
      if ((int)pq.size() < l)
      {
        pq.push(diff);
        i++;
        continue;
      }
      if ((int)pq.size() == l)
      {
        if (l > 0 && diff > pq.top())
        {
          b -= pq.top();
          pq.pop();
          pq.push(diff);
        }
        else
        {
          b -= diff;
        }
      }
      if (b < 0)
      {
        return i;
      }
      i++;
    }
    return i;
  }
};