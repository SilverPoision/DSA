class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> ans;

    int i = (n - 1) / 2;
    int j = n - 1;
    while (i >= 0)
    {
      ans.push_back(nums[i--]);
      if (j > (n - 1) / 2)
        ans.push_back(nums[j--]);
    }

    nums = ans;
  }
};

void wiggleSort(int *nums, int numsSize)
{
  int arr[5001];
  for (int i = 0; i < 5001; i++)
    arr[i] = 0;
  for (int i = 0; i < numsSize; i++)
  {
    arr[nums[i]]++;
  }
  int end = 5000;
  int in = 1; // start to  fill largest value from 1 index
  while (in < numsSize && end > -1)
  {
    if (arr[end] == 0)
    {
      end--;
      continue;
    }
    else
    {
      nums[in] = end;
      in += 2;
      arr[end]--;
    }
  }
  in = 0; // start to fill next set of values from index 0
  while (in < numsSize && end > -1)
  {
    if (arr[end] == 0)
    {
      end--;
      continue;
    }
    else
    {
      nums[in] = end;
      in += 2;
      arr[end]--;
    }
  }
}