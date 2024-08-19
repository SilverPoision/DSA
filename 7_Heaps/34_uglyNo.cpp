class Solution
{
public:
  int nthUglyNumber(int n)
  {
    vector<long long> num;
    num.push_back(1);
    int i2 = 0, i3 = 0, i5 = 0;

    for (int i = 1; i < n; i++)
    {
      int nextNum = min({num[i2] * (long long)2, num[i3] * (long long)3, num[i5] * (long long)5});
      num.push_back(nextNum);

      if (nextNum == (num[i2] * (long long)2))
        i2++;
      if (nextNum == (num[i3] * (long long)3))
        i3++;
      if (nextNum == (num[i5] * (long long)5))
        i5++;
    }

    return num[n - 1];
  }
};

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