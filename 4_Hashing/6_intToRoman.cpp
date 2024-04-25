class Solution
{
public:
  unordered_map<int, string> hash;
  string intToRoman(int num)
  {
    vector<string> notations = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans = "";
    int i = 0;

    while (num)
    {
      if (num >= nums[i])
      {
        ans += notations[i];
        num -= nums[i];
      }
      else
        i++;
    }

    return ans;
  }
};