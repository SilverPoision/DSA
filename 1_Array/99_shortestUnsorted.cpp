class Solution
{
public:
  // https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
  int findUnsortedSubarray(vector<int> &nums)
  {
    int n = nums.size();

    int start = -1, end = -1;
    int max1 = nums[0], min1 = nums[n - 1];
    for (int i = 1; i < n; i++)
    {
      if (nums[i] < max1)
        end = i;
      max1 = max(max1, nums[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
      if (nums[i] > min1)
        start = i;
      min1 = min(min1, nums[i]);
    }
    if (start == -1)
      return 0;
    else
      return end - start + 1;
  }
};

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> mini(n, 1e9), maxi(n, -1e9);

    maxi[0] = nums[0];
    mini[n - 1] = nums[n - 1];

    for (int i = 1; i < n; i++)
    {
      maxi[i] = max(maxi[i - 1], nums[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
      mini[i] = min(mini[i + 1], nums[i + 1]);
    }

    int start = -1, end = -1;
    for (int i = 0; i < n; i++)
    {
      bool flag = false;
      if (mini[i] < nums[i] || maxi[i] > nums[i])
      {
        if (start == -1)
          start = i;
        flag = true;
      }
      if (flag)
        end = i;
    }

    if (start == -1 && end == -1)
      return 0;

    return end - start + 1;
  }
};

class Solution
{
  // https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    int n = nums.size();
    int start = -1, end = -1;
    int maxi = -1e9;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        if ((i != j && nums[i] > nums[j]) || maxi > nums[j])
        {
          if (start == -1)
            start = i;
          flag = true;
          break;
        }
      }
      maxi = max(maxi, nums[i]);
      if (flag)
        end = i;
      flag = false;
    }
    if (start == -1 && end == -1)
      return 0;
    cout << start << " " << end;
    return end - start + 1;
  }
};