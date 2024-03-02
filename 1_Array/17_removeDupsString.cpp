#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

/*
String is given as input that contains only lowercase letters,
remove duplicate letters so that every letter appears once
In O(n) Time Complexity and O(1) Space Complexity

Solution:
1. Make a arr of 256 lenth and put -1 in the ascii of string
ele and then verify them.
*/

class Solution
{
public:
  string removeDuplicateLetters(string s)
  {
    map<char, int> freq;
    map<char, bool> seen;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
      freq[s[i]]++;
      seen[s[i]] = false;
    }

    stack<char> st;
    for (int i = 0; i < n; i++)
    {
      if (seen[s[i]] == false)
      {
        while (!st.empty() && st.top() > s[i] && freq[st.top()] > 0)
        {
          seen[st.top()] = false;
          st.pop();
        }
        st.push(s[i]);
        freq[s[i]]--;
        seen[s[i]] = true;
      }
      else
      {
        freq[s[i]]--;
      }
    }

    string str;
    while (!st.empty())
    {
      str.push_back(st.top());
      st.pop();
    }
    reverse(str.begin(), str.end());
    return str;
  }
};

int main()
{
  string str = "abacbc";
  string str1 = removeDuplicates(str);
  cout << str1 << endl;
  return 0;
}

/* Try more Inputs

case1:
actual = removeDuplicates("cbacdcbc")
expected = "acdb"

case2:
actual = removeDuplicates("Java")
expected = "Jav"

case3:
actual = removeDuplicates("abacbc")
expected = "abc"


*/