class Solution
{
public:
  int maxScore(vector<int> &arr, int k)
  {
    int i = 0, j = 0;
    int n = arr.size();

    int sum = 0, tot = 0;
    int ans = 0;
    int size = 0;

    for (auto it : arr)
      sum += it;

    while (j <= n)
    {
      if (size != n - k)
      {
        tot += arr[j++];
        size++;
      }
      else
      {
        ans = max(ans, sum - tot);
        if (j == n)
          break;
        tot -= arr[i++];
        tot += arr[j++];
      }
    }

    return ans;
  }
};