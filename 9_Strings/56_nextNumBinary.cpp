class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1
  string binaryNextNumber(string s)
  {
    while (s[0] == '0')
      s = s.substr(1);

    int carry = 1;
    string ans = "";

    for (int i = s.size() - 1; i >= 0; i--)
    {
      if (s[i] == '1')
        s[i] = '0';
      else
      {
        s[i] = '1';
        return s;
      }
      ans.push_back('0');
    }

    return '1' + ans;
  }
};