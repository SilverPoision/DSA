class Solution
{
public:
  // https://leetcode.com/problems/kth-distinct-string-in-an-array/?envType=daily-question&envId=2024-08-05
  string kthDistinct(vector<string> &arr, int k)
  {
    unordered_map<string, int> hash;

    for (auto &it : arr)
      hash[it]++;

    for (auto &it : arr)
    {
      if (hash[it] == 1)
      {
        k--;
        if (k == 0)
          return it;
      }
    }

    return "";
  }
};