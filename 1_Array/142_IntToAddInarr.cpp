class Solution
{
public:
  // https://leetcode.com/problems/find-the-integer-added-to-array-ii/
  bool check(vector<int> &nums1, vector<int> &nums2, int diff)
  {
    int cnt = 0;
    for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); i++)
    {
      if (nums2[j] - nums1[i] != diff)
        cnt++;
      else
        j++;
    }

    return cnt <= 2;
  }
  int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
  {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n = nums1.size();
    int m = nums2.size();

    int mini = 1e9;
    for (int i = 0; i < min(3, n); i++)
    {
      int x = nums2[0] - nums1[i];
      if (check(nums1, nums2, x))
      {
        mini = min(mini, x);
      }
    }

    return mini;
  }
};

class Solution
{
public:
  int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
  {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n = nums1.size();
    int m = nums2.size();

    int mini = 1e9;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        vector<int> v;
        for (int k = 0; k < n; k++)
        {
          if (k != i && k != j)
          {
            v.push_back(nums1[k]);
          }
        }
        int a1 = nums2[0] - v[0];
        bool a = true;
        for (int i = 1; i < m; i++)
        {
          int ele = nums2[i] - v[i];
          if (ele != a1)
          {
            a = false;
            break;
          }
        }
        if (a == true)
        {
          mini = min(mini, a1);
        }
      }
    }

    return mini;
  }
};