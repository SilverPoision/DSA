// Write an algorithm to find out next greater number to
// given number with the same set of digits Asked in :

/*
Solution:
1. Check weather which of the pairs from that last has first
smallest no in the left and stop the iteration
2. Then store the index in a min var and the value of the arr[i -2]
in ele var
3. Then start checking the immediat smallest no is the right of the
selected no.
4. Then swap the 2 nos and sort the arr from where you sorted.
*/

class Solution
{
public:
  int nextGreaterElement(int n)
  {
    // next Permutation
    string s = to_string(n);

    int i;
    for (i = s.size() - 1; i >= 1; i--)
    {
      if (s[i] > s[i - 1])
      {
        i--;
        break;
      }
    }
    int mini = 1e9;
    int ind = 0;
    for (int k = i + 1; k < s.size(); k++)
    {
      if (s[k] > s[i] & mini > s[k])
      {
        mini = s[k];
        ind = k;
      }
    }
    swap(s[i], s[ind]);
    sort(s.begin() + i + 1, s.end());

    long next = stol(s);
    return next == n || next > INT_MAX || next < n ? -1 : next;
  }
};