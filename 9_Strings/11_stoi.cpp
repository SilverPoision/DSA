class Solution
{
public:
  int myAtoi(string s)
  {
    double ans = 0;
    int sign = 1;
    int i = 0;

    while (s[i] == ' ')
      i++;

    bool neg = s[i] == '-';
    bool pos = s[i] == '+';

    pos == true ? i++ : i;
    neg == true ? i++ : i;

    while (i < s.size() && s[i] >= '0' && s[i] <= '9')
    {
      ans = ans * 10 + (s[i] - '0');
      i++;
    }

    ans = neg ? ans * -1 : ans;

    if (ans > INT_MAX)
      ans = INT_MAX;
    if (ans < INT_MIN)
      ans = INT_MIN;

    return (int)ans;
  }
};

class Solution
{
public:
  int convert(string &s, int i, int sign, long res)
  {
    if ((sign * res) >= INT_MAX)
      return INT_MAX;
    if ((sign * res) <= INT_MIN)
      return INT_MIN;

    if (i >= s.size() || s[i] < '0' || s[i] > '9')
      return sign * res;

    res = convert(s, i + 1, sign, (res * 10 + (s[i] - '0')));

    return res;
  }
  int myAtoi(string s)
  {
    int i = 0;
    int sign = 1;
    while (i < s.size() && s[i] == ' ')
      i++;

    if (s[i] == '+')
      i++;
    else if (s[i] == '-')
    {
      sign = -1;
      i++;
    }
    return convert(s, i, sign, 0);
  }
};