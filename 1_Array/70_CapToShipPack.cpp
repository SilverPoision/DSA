class Solution
{
public:
  bool canShip(vector<int> &w, int days, int mid)
  {
    int temp = 0;
    int cntDays = 1;

    for (auto it : w)
    {
      if ((temp + it) > mid)
      {
        cntDays++;
        temp = it;
      }
      else
      {
        temp += it;
      }
    }

    return days >= cntDays;
  }
  int shipWithinDays(vector<int> &weights, int days)
  {
    int low = -1e9, high = 0;

    for (auto it : weights)
    {
      low = max(low, it);
      high += it;
    }

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (canShip(weights, days, mid))
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