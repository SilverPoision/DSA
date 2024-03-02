class Solution
{
public:
  bool checkConfig(vector<int> &stalls, int k, int mid)
  {
    int cnt = 1;
    int lastCow = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {

      if (stalls[i] - lastCow >= mid)
      {
        cnt++;
        lastCow = stalls[i];
      }

      if (cnt == k)
      {
        return true;
      }
    }

    return false;
  }

  int solve(int n, int k, vector<int> &stalls)
  {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[0] - stalls[n - 1];
    int ans = 0;

    for (auto it : stalls)
      high = max(high, it);

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (checkConfig(stalls, k, mid))
      {
        ans = mid;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return ans;
  }
};