class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/smallest-number5829/1
  string smallestNumber(int s, int d)
  {
    // code here
    if (s > d * 9)
      return "-1";
    string ans = "";

    int i = 1;
    while (i <= d)
    {
      int num = (s - (d - i) * 9) <= 0 ? 0 : s - (d - i) * 9;

      if (num == 0 && i == 1)
        num = 1;

      ans += (num + '0');
      i++;
      s -= num;
    }

    return ans;
  }
};