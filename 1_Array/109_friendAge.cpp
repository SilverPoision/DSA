int numFriendRequests(vector<int> &ages)
{
  unordered_map<int, int> count;
  for (int &age : ages)
    count[age]++;
  int res = 0;
  for (auto &a : count)
    for (auto &b : count)
      if (request(a.first, b.first))
        res += a.second * (b.second - (a.first == b.first ? 1 : 0));
  return res;
}

bool request(int a, int b)
{
  return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
}

class Solution
{
public:
  int numFriendRequests(vector<int> &ages)
  {
    int n = ages.size();
    sort(ages.begin(), ages.end(), greater<int>());
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      int l = i, r = n - 1;
      int k = (ages[i] * 0.5 + 7);

      while (l <= r)
      {
        int mid = (l + r) / 2;

        if (ages[mid] > k)
        {
          l = mid + 1;
        }
        else
        {
          r = mid - 1;
        }
      }
      for (int j = i + 1; j <= l - 1; j++)
      {
        if (ages[i] == ages[j])
          cnt++;
        cnt++;
      }
    }

    return cnt;
  }
};