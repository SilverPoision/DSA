class Solution
{
public:
  int nthUglyNumber(int n)
  {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    unordered_map<long long, bool> h;
    pq.push(1);

    while (true)
    {
      long long top = pq.top();
      pq.pop();
      if (h.find(top) != h.end())
        continue;
      n--;

      if (n == 0)
        return top;
      h[top] = true;

      pq.push(top * (long long)2);
      pq.push(top * (long long)3);
      pq.push(top * (long long)5);
    }

    return -1;
  }
};