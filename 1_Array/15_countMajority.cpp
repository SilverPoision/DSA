#include <iostream>
using namespace std;

/*
 Given an array of integer, write an efficient algorithm to
 find majority number in that array in Time Complexity O(n) and
 Space Complexity O(1)

 Solution:
 1. set ele = arr[0] and run a loop from i =1 amd check if the
 ele == arr[i] if yes then count++ else count--
 2. Check if the count == 0 if yes then update the majority ele
 and count=1;

 O(N),O(1);
*/

// Function to return majority element present in given array
class Solution
{
public:
  bool verifyEle(int x, vector<int> &nums)
  {
    int cnt = 0;
    for (auto it : nums)
    {
      if (it == x)
        cnt++;
    }

    return cnt > nums.size() / 2;
  }
  int majorityElement(vector<int> &nums)
  {
    int count = 1, ele = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] == ele)
      {
        count++;
      }
      else
      {
        count--;
      }

      if (count <= 0)
      {
        ele = nums[i];
        count = 1;
      }
    }

    return verifyEle(ele, nums) == true ? ele : -1;
  }
};