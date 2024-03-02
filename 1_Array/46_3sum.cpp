class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int j = i + 1;
      int k = n - 1;
      while (j < k)
      {
        int num = nums[i] + nums[j] + nums[k];
        if (num == 0)
        {
          ans.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;
          while (j < k && nums[k] == nums[k + 1])
            k--;
          while (j < k && nums[j] == nums[j - 1])
            j++;
        }
        else if (num > 0)
        {
          k--;
        }
        else
        {
          j++;
        }
      }
    }

    return ans;
  }
};

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    bool flag = true;
    for (auto it : nums)
    {
      if (it != 0)
        flag = false;
    }
    if (flag)
      return {{0, 0, 0}};
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
      int it = nums[i];
      int req = it == 0 ? 0 : -1 * it;

      int high = nums.size() - 1, low = 0;

      while (low < high)
      {
        if (i == low)
        {
          low++;
          continue;
        }
        if (i == high)
        {
          high--;
          continue;
        }
        int num = nums[low] + nums[high];
        if (num == req)
        {
          vector<int> temp;
          temp = {it, nums[low], nums[high]};
          sort(temp.begin(), temp.end());
          ans.insert(temp);
          high--;
        }
        else if (num > req)
        {
          high--;
        }
        else
        {
          low++;
        }
      }
    }

    vector<vector<int>> a;
    for (auto it : ans)
    {
      a.push_back(it);
    }
    return a;
  }
};