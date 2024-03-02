class Solution
{
public:
  int minAddToMakeValid(string s)
  {
    int req = 0, open = 0;
    for (auto it : s)
    {
      if (it == '(')
        open++;
      else if (it == ')' && open > 0)
        open--;
      else
        req++;
    }

    if (open > 0)
      return open + req;

    return req;
  }
};

// Brackets Reversal

#include <bits/stdc++.h>
int findMinimumCost(string str)
{
  // Write your code here
  if (str.size() % 2)
    return -1;

  int open = 0, close = 0;

  for (auto it : str)
  {
    if (it == '{')
      open++;
    else if (it == '}' && open > 0)
      open--;
    else
      close++;
  }

  return ((open + 1) / 2) + ((close + 1) / 2);
}