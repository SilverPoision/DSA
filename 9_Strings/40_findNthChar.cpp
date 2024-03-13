class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1
  char nthCharacter(string s, int r, int n)
  {
    // code here
    while (r--)
    {
      string temp = "";
      for (int i = 0; i < s.size(); i++)
      {
        if (s[i] == '0')
        {
          temp += "01";
        }
        else
        {
          temp += "10";
        }
        if (temp.size() > n)
          break;
      }
      s = temp;
    }

    return s[n];
  }
};