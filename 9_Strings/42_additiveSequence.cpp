class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/additive-sequence/1
  // https://www.youtube.com/watch?v=OEob6gI89WM
  bool isAdditiveSequence(string num)
  {
    // Your code herei
    int n = num.size();

    int first = 0;

    for (int i = 0; i < n - 2; i++)
    {
      first = first * 10 + (num[i] - '0');
      int second = 0;
      for (int j = i + 1; j < n - 1; j++)
      {
        second = second * 10 + (num[j] - '0');
        int n1 = first;
        int n2 = second;
        int third = 0;
        int k = 0;
        for (k = j + 1; k < n; k++)
        {
          third = third * 10 + (num[k] - '0');
          if (n1 + n2 == third)
          {
            n1 = n2;
            n2 = third;
            third = 0;
          }
        }
        if (k == n && third == 0)
          return true;
      }
    }
    return false;
  }
};