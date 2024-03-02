class Solution
{
public:
  bool checkFlowers(vector<int> &bloom, int m, int k, int mid)
  {
    int curr = 0, temp = 0;
    for (int i = 0; i < bloom.size(); i++)
    {
      if (bloom[i] <= mid)
      {
        temp++;
      }
      else
      {
        temp = 0;
      }

      if (temp == k)
      {
        curr++;
        temp = 0;
      }
    }
    return curr >= m;
  }

  int minDays(vector<int> &bloomDay, int m, int k)
  {
    long long int prod = (long long int)m * (long long int)k;
    if (bloomDay.size() < prod)
      return -1;
    int n = bloomDay.size();

    int low = 0, high = 1e9;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (checkFlowers(bloomDay, m, k, mid))
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return low;
  }
};