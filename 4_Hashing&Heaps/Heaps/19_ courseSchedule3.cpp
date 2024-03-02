class Solution
{
public:
  int scheduleCourse(vector<vector<int>> &c)
  {
    sort(c.begin(), c.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    priority_queue<int> pq;
    int sum = 0;

    for (auto it : c)
    {
      sum += it[0];
      pq.push(it[0]);

      if (sum > it[1])
      {
        sum -= pq.top();
        pq.pop();
      }
    }

    return pq.size();
  }
};