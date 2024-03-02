class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != i)
      {
        return i;
      }
    }
    return -1;
  }
};

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int sum = 0;

    for (auto it : nums)
    {
      sum += it;
    }

    return n * (n + 1) / 2 - sum;
  }
};

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n; i++)
    {
      xor1 ^= nums[i];
      xor2 ^= (i + 1);
    }

    return xor1 ^ xor2;
  }
};