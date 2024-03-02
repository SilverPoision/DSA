class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int low = 0, high = numbers.size() - 1;
    vector<int> ans;
    while (low < high)
    {
      int num = numbers[low] + numbers[high];
      if (num == target)
      {
        break;
      }
      else if (num > target)
      {
        high--;
      }
      else
      {
        low++;
      }
    }
    ans.push_back(low + 1);
    ans.push_back(high + 1);
    return ans;
  }
};

// for unsorted arr
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); i++)
    {
      if (hash.find(target - nums[i]) != hash.end())
      {
        return {i, hash[target - nums[i]]};
      }

      hash[nums[i]] = i;
    }
    return {-1, -1};
  }
};