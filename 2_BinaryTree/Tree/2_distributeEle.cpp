#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;

class Solution
{
public:
  // https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/
  typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
               tree_order_statistics_node_update>
      ordered_set;
  vector<int> resultArray(vector<int> &nums)
  {
    vector<int> arr1, arr2;
    ordered_set s1, s2;

    arr1.push_back(nums[0]);
    s1.insert({nums[0], 0});
    arr2.push_back(nums[1]);
    s2.insert({nums[1], 1});

    for (int i = 2; i < nums.size(); i++)
    {
      int ele = nums[i] + 1;

      int id1 = s1.size() - s1.order_of_key({ele, 0});
      int id2 = s2.size() - s2.order_of_key({ele, 0});

      if (id1 > id2)
      {
        arr1.push_back(nums[i]);
        s1.insert({nums[i], i});
      }
      else if (id1 < id2)
      {
        arr2.push_back(nums[i]);
        s2.insert({nums[i], i});
      }
      else
      {
        if (arr1.size() <= arr2.size())
        {
          arr1.push_back(nums[i]);
          s1.insert({nums[i], i});
        }
        else
        {
          arr2.push_back(nums[i]);
          s2.insert({nums[i], i});
        }
      }
    }

    for (auto it : arr2)
      arr1.push_back(it);

    return arr1;
  }
};