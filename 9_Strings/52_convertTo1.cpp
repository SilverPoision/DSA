class Solution
{
public:
  // https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2024-05-29
  int numSteps(string s)
  {
    int n = s.size();

    int cnt = 0;
    while (s.size() != 1 && s[0] != 1)
    {
      if (s[s.size() - 1] == '0')
        s.pop_back();
      else
      {
        int carry = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
          if (s[i] == '1')
            s[i] = '0';
          else
          {
            s[i] = '1';
            carry = 0;
            break;
          }
        }
        if (carry)
          s.insert(0, "1");
      }
      cnt++;
    }

    return cnt;
  }
};

// optimal
class Solution
{
public:
  int numSteps(string s)
  {
    int carry = 0, steps = 0;
    for (int i = s.length() - 1; i > 0; i--)
    {
      if ((s[i] - '0') + carry == 1)
      {
        steps += 2;
        carry = 1;
      }
      else
      {
        steps++;
      }
    }
    return steps + carry;
  }
};
