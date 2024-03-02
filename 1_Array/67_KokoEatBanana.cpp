class Solution
{
public:
  double checkIfSheCanEat(vector<int> &piles, long double mid)
  {
    long double hr = 0.0;
    for (auto it : piles)
    {
      long double i = (long double)it;
      hr += ceil((i / mid));
    }

    return hr;
  }
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int low = 1, high = 1e9;

    while (low <= high)
    {
      long long int mid = low + (high - low) / 2;

      long double check = checkIfSheCanEat(piles, (long double)mid);
      if (check <= h)
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