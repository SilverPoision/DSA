/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
  int findPeak(int l, int r, MountainArray &mnt)
  {
    while (l < r)
    {
      int m = l + (r - l) / 2;
      if (mnt.get(m) > mnt.get(m + 1))
      {
        r = m;
      }
      else
      {
        l = m + 1;
      }
    }

    return l;
  }

  int binarySearch(int low, int high, int target, MountainArray &mnt, bool reverse)
  {
    while (low != high)
    {
      int mid = low + (high - low) / 2;

      if (reverse)
      {
        if (mnt.get(mid) > target)
        {
          low = mid + 1;
        }
        else
        {
          high = mid; // if conditions is not defined to exit the loop then we dont need to
                      // move right pointer by m-1 just move it by m and they(l, r) will converge to one index and the loop will break
        }
      }
      else
      {
        if (mnt.get(mid) < target)
        {
          low = mid + 1;
        }
        else
        {
          high = mid;
        }
      }
    }

    return low;
  }

  int findInMountainArray(int target, MountainArray &mnt)
  {
    int n = mnt.length();

    int peakEle = findPeak(0, n - 1, mnt);

    int incIdx = binarySearch(0, peakEle, target, mnt, false);
    if (mnt.get(incIdx) == target)
      return incIdx;

    int decIdx = binarySearch(peakEle + 1, n - 1, target, mnt, true);
    if (mnt.get(decIdx) == target)
      return decIdx;

    return -1;
  }
};