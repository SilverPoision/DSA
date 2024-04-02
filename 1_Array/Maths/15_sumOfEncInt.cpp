class Solution
{
public:
  // https://leetcode.com/problems/find-the-sum-of-encrypted-integers/description/
  int encrypt(int x)
  {
    int maxi = -1;
    int cnt = 0;

    while (x)
    {
      maxi = max(maxi, x % 10);
      x /= 10;
      cnt++;
    }

    long long num = 0;
    while (cnt)
    {
      num = num * 10 + maxi;
      cnt--;
    }

    return num;
  }
  int sumOfEncryptedInt(vector<int> &nums)
  {
    int ans = 0;
    for (auto it : nums)
    {
      ans += encrypt(it);
    }

    return ans;
  }
};