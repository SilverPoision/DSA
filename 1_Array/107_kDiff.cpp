class Solution
{
public:
  int findPairs(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());

    set<pair<int, int>> ans;
    int i = 0;
    int j = 1;

    while (j < nums.size())
    {
      int diff = nums[j] - nums[i];
      if (diff == k)
      {
        ans.insert({nums[i], nums[j]});
        i++;
        j++;
      }

      else if (diff > k)
      {
        i++;
      }

      else
        j++;

      if (i == j)
        j++;
    }

    return ans.size();
  }
};
// same
class Solution
{
public:
  int findPairs(vector<int> &nums, int k)
  {
    int n = nums.size();
    set<pair<int, int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
      int req = nums[i] + k;
      int l = 0, h = n - 1;
      while (l <= h)
      {
        int mid = (l + h) / 2;

        if (nums[mid] == req && mid != i)
        {
          if (nums[i] < nums[mid])
            ans.insert({nums[i], nums[mid]});
          else
            ans.insert({nums[mid], nums[i]});
          break;
        }

        if (nums[mid] < req)
        {
          l = mid + 1;
        }
        else
        {
          h = mid - 1;
        }
      }
    }

    return ans.size();
  }
};

// less optimal
class Solution
{
public:
  // https://leetcode.com/problems/k-diff-pairs-in-an-array/
  int findPairs(vector<int> &nums, int k)
  {
    int n = nums.size();
    set<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (abs(nums[i] - nums[j]) == k)
        {
          if (nums[i] > nums[j])
            ans.insert({nums[i], nums[j]});
          else
            ans.insert({nums[j], nums[i]});
        }
      }
    }

    return ans.size();
  }
};