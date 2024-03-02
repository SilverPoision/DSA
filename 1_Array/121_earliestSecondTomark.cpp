class Solution
{
public:
  // https://leetcode.com/problems/earliest-second-to-mark-indices-i/?envType=list&envId=opbzdrut
  bool check(vector<int> &nums, vector<int> &ind, int idx)
  {
    int n = ind.size();
    unordered_map<int, int> hash;
    for (int i = 0; i < idx; i++)
    {
      hash[ind[i]] = i;
    }

    if (hash.size() != nums.size())
      return false;

    int cnt = 0;

    for (int i = 0; i < idx; i++)
    {
      if (i == hash[ind[i]])
      {
        if (cnt < nums[ind[i] - 1])
          return false;
        cnt -= nums[ind[i] - 1];
      }
      else
      {
        cnt++;
      }
    }

    return true;
  }
  int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &ind)
  {
    int low = 0, high = ind.size();
    int res = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (check(nums, ind, mid))
      {
        res = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return res;
  }
};