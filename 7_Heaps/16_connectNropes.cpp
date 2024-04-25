int minCost(int arr[], int n)
{
  long long ans = 0;
  priority_queue<long long, vector<long long>, greater<long long>> min;

  for (long long i = 0; i < n; i++)
    min.push(arr[i]);

  while (min.size() > 1)
  {
    long long a = min.top();
    min.pop();
    long long b = min.top();
    min.pop();

    ans += a + b;

    min.push(a + b);
  }

  return ans;
}
