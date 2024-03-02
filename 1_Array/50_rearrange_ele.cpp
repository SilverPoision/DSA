class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    vector<int> ans;
    int n = nums.size();

    int pos = 0, neg = 0;
    int flag = true;

    while (ans.size() != n)
    {
      if (flag)
      {
        if (nums[pos] > 0)
        {
          ans.push_back(nums[pos]);
          flag = !flag;
        }
        pos++;
      }
      else
      {
        if (nums[neg] < 0)
        {
          ans.push_back(nums[neg]);
          flag = !flag;
        }
        neg++;
      }
    }

    return ans;
  }
};

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans(n);
    int i = 0;
    int pos = 0;
    int neg = 1;

    while (i < n)
    {
      if (nums[i] >= 0)
      {
        ans[pos] = nums[i];
        pos += 2;
      }
      else
      {
        ans[neg] = nums[i];
        neg += 2;
      }
      i++;
    }

    return ans;
  }
};

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> negs;
    vector<int> pos;
    for (auto it : nums)
    {
      if (it < 0)
      {
        negs.push_back(it);
      }
      else
      {
        pos.push_back(it);
      }
    }

    reverse(negs.begin(), negs.end());
    reverse(pos.begin(), pos.end());
    int i = 0;

    while (negs.size() > 0 && pos.size() > 0)
    {
      nums[i++] = pos.back();
      pos.pop_back();
      nums[i++] = negs.back();
      negs.pop_back();
    }
    return nums;
  }
};