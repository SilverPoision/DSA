#include <bits/stdc++.h>
using namespace std;

/*
Given two strings string1 and string2 , return the minimum
window in string1 which will contain all the characters in
string2 in Time Complexity O(n) and Space Complexity O(1)

Solution:
First check if the length of the string is less than the length
of the given pattern, if yes then “no such window can exist “.
Store the occurrence of characters of the given pattern in a
hash_pat[].
we will be using two pointer technique basically
Start matching the characters of pattern with the characters of
string i.e. increment count if a character matches.
Check if (count == length of pattern ) this means a window is
found.
If such a window found, try to minimize it by removing extra
characters from the beginning of the current window.
delete one character from first and again find this deleted key
at right, once found apply step 5 .
Update min_length.
Print the minimum length window.
*/

class Solution
{
public:
  string minWindow(string s, string t)
  {
    if (t.size() == 0)
      return "";
    if (t.size() > s.size())
      return "";
    int window[256] = {0};
    int count[256] = {0};

    for (int i = 0; i < t.size(); i++)
    {
      count[t[i]]++;
    }

    int start = 0, startIndex = -1, minLen = 1e9;
    int have = 0, n = t.size();

    for (int i = 0; i < s.size(); i++)
    {
      int k = s[i];
      window[k]++;
      if (window[k] <= count[k])
      {
        have++;
      }

      if (have == n)
      {
        while (window[s[start]] > count[s[start]] || count[s[start]] == 0)
        {
          if (window[s[start]] > count[s[start]])
          {
            window[s[start]]--;
          }
          start++;
        }
        int len_window = i - start + 1;

        if (minLen > len_window)
        {
          minLen = len_window;
          startIndex = start;
        }
      }
    }

    if (startIndex == -1)
      return "";

    return s.substr(startIndex, minLen);
  }
};

int main()
{
  string str = "aabcbcdbca";
  string ptr = "abcd";

  cout << "Smallest window is : \n"
       << findMinWindow(str, ptr);
  return 0;
}

/* Try more Inputs
case 1:
actual = findMinWindow("a","a")
expected = Smallest window is : a

case2:
 actual = findMinWindow("zaaskzaa", "zsk")
 expected = Smallest window is : skz

case3:
actual = findMinWindow("tutorial","oti")
expected = Smallest window is : tori


*/