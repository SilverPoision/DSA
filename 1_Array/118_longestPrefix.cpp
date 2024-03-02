class Solution
{
public:
  // https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
  {
    unordered_set<int> hash;

    for (auto it : arr1)
    {
      int num = it;
      while (num)
      {
        hash.insert(num);
        num /= 10;
      }
    }

    int ans = 0;
    for (auto it : arr2)
    {
      int num = it;
      while (num)
      {
        if (hash.count(num))
        {
          ans = max(ans, num);
          break;
        }
        num /= 10;
      }
    }

    return ans ? to_string(ans).size() : 0;
  }
};