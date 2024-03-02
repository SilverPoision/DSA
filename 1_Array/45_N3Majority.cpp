class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
      if (cnt1 == 0 && ele2 != nums[i])
      {
        cnt1 = 1;
        ele1 = nums[i];
      }
      else if (cnt2 == 0 && ele1 != nums[i])
      {
        cnt2 = 1;
        ele2 = nums[i];
      }
      else if (ele1 == nums[i])
      {
        cnt1++;
      }
      else if (ele2 == nums[i])
      {
        cnt2++;
      }
      else
      {
        cnt1--;
        cnt2--;
      }
    }

    vector<int> ls;

    cnt1 = 0, cnt2 = 0;

    for (auto it : nums)
    {
      if (it == ele1)
        cnt1++;
      if (it == ele2)
        cnt2++;
    }

    int min = (int)(nums.size() / 3) + 1;
    if (cnt1 >= min)
      ls.push_back(ele1);
    if (cnt2 >= min)
      ls.push_back(ele2);

    return ls;
  }
};