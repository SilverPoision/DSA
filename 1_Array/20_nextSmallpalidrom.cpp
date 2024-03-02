#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/*
Next Smallest Palindrome
HardAccuracy: 19.63%Submissions: 17K+Points: 8
Done with this problem? Now use these skills to apply for a job in Job-A-Thon 20!
Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome strictly larger than the given number.

Example 1:

Input:
N = 11
Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
Output: 9 4 1 8 8 0 8 8 1 4 9
Explanation: Next smallest palindrome is
94188088149.

Solution:
1. if n is even then suppose 2436 then check if the mid-1 > mid
if yes then mid = mid-1 and tale half the array and just replicate the
first half to the second half;
if the mid-1 < mid then just add 1 to mid-1 and do the same;
if n is odd then suppose 28749 then tak mid and compare and
check mid-1 > mid+1 if yes then mid+1 = mid-1 and replicate after the mid;
else mid++ and replicate the  first half to second half.

Exceptions:
If all the no are 9 like 999 then just count the no of 9's and
just put noofnine-1 0's between 2 1's like 999 > 1001;
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void convert(vector<int> &num, int n)
  {
    int mid = n / 2;
    int i = mid - 1;
    int j = n % 2 == 0 ? mid : mid + 1;
    bool leftSmall = false;

    while (i >= 0 && num[i] == num[j])
    {
      i--;
      j++;
    }

    if (i < 0 || num[i] < num[j])
      leftSmall = true;

    while (i >= 0)
    {
      num[j++] = num[i--];
    }

    if (leftSmall)
    {
      int carry = 1;
      i = mid - 1;
      if (n % 2 == 1)
      {
        num[mid] += carry;
        carry = num[mid] / 10;
        num[mid] %= 10;
        j = mid + 1;
      }
      else
      {
        j = mid;
      }

      while (i >= 0)
      {
        num[i] += carry;
        carry = num[i] / 10;
        num[i] %= 10;

        num[j++] = num[i--];
      }
    }
  }

  bool checkNine(vector<int> &num, int n)
  {
    for (int i = 0; i < n; i++)
    {
      if (num[i] != 9)
        return false;
    }
    return true;
  }

  vector<int> generateNextPalindrome(int num1[], int n)
  {
    vector<int> num;
    int i = 0;
    while (i < n)
    {
      num.push_back(num1[i++]);
    }

    if (checkNine(num, n))
    {
      num.clear();
      num.push_back(1);
      for (int i = 1; i < n; i++)
      {
        num.push_back(0);
      }
      num.push_back(1);
      return num;
    }

    convert(num, n);

    return num;
  }
};

/* Try more Inputs
case 1:
actual = nextPalindromeProblem([9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2],11)
expected = 94188088149

case2:
 actual = nextPalindromeProblem([1,2,1],3)
 expected = 131

case3:
actual = nextPalindromeProblem([2,3,5,4,5],5)
expected = 23632
*/