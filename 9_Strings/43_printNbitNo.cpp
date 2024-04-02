class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/
  void f(string s, int one, int zero, int n, vector<string> &ans)
  {
    if (s.size() == n)
    {
      ans.push_back(s);
      return;
    }

    f(s + "1", one + 1, zero, n, ans);
    if (one > zero)
      f(s + '0', one, zero + 1, n, ans);
  }
  vector<string> NBitBinary(int n)
  {
    // Your code goes here
    vector<string> ans;
    f("", 0, 0, n, ans);

    return ans;
  }
};