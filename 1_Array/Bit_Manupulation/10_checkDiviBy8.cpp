class Solution
{
public:
  // https://www.geeksforgeeks.org/check-large-number-divisible-8-not/
  int DivisibleByEight(string s)
  {
    // code here
    int n = stoi(S);

    return (n & 7) == 0 ? 1 : -1;
  }
};

class Solution
{
public:
  int DivisibleByEight(string s)
  {
    // code here
    int n = s.size();
    if (n == 1)
      return ((s[0] - '0') % 8) == 0;
    if (n == 2)
      return (((s[0] - '0') * 10 + s[1] - '0') % 8) == 0;
    int num = stoi(s.substr(n - 3));

    return (num % 8) == 0 ? 1 : -1;
  }
};