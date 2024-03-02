class Solution
{
public:
  string getPermutation(int n, int k)
  {
    // Taking ex on 17th permutation and n = 4;
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
      nums.push_back(i);
      fact = fact * i; // 6
    }
    string ans = "";
    nums.push_back(n);
    //[1,2,3,4];
    k--;

    while (true)
    {
      ans = ans + to_string(nums[k / fact]); // k / fact = 16/6;
      nums.erase(nums.begin() + k / fact);

      if (nums.size() == 0)
        return ans;
      k = k % fact;              // 16 % 6 = 4;
      fact = fact / nums.size(); // 6 / 3 = 2;
    }
  }
};