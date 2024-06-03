class Solution
{
public:
  // https://leetcode.com/problems/find-subarray-with-bitwise-and-closest-to-k/
  void addEle(vector<int> &bit, int el)
  {
    for (int i = 0; i < 32; i++)
    {
      if (!(el & (1 << i)))
      {
        bit[i]++;
      }
    }
  }
  void subEle(vector<int> &bit, int el)
  {
    for (int i = 0; i < 32; i++)
    {
      if (!(el & (1 << i)))
      {
        bit[i]--;
      }
    }
  }
  int calcAnd(vector<int> &bit)
  {
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
      ans += (1 << i) * (bit[i] == 0);
    }

    return ans;
  }
  int minimumDifference(vector<int> &nums, int k)
  {
    int i = 0, j = 0, rangeAnd = 0;
    vector<int> bit(32, 0);

    int mini = 1e9;

    while (j < nums.size())
    {
      addEle(bit, nums[j]);
      rangeAnd = calcAnd(bit);
      mini = min(mini, abs(rangeAnd - k));

      while (rangeAnd < k && i < j)
      {
        subEle(bit, nums[i++]);
        rangeAnd = calcAnd(bit);
        mini = min(mini, abs(rangeAnd - k));
      }

      j++;
    }

    return mini;
  }
};