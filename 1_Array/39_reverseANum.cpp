#include <bits/stdc++.h>
using namespace std;

int revNum(int num)
{
  vector<int> nums;
  while (num != 0)
  {
    nums.push_back(num % 10);
    num = num / 10;
  }

  int n = 0;

  for (auto it : nums)
  {
    n = 10 * n + it;
  }

  return n;
}

int main()
{
  int num = 123;
  int rev = revNum(num);
  cout << rev;
  return 0;
}