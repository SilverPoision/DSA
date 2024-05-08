/*
We put the cumaplative xor of words in map and when we encounter a
substrng with all even charthe xor becomes 0 and when we find 0 in
map we get the value and we add one. when we encounter an odd xor
then we xor it with all the chars to check if a single char can make
the xor 0 if yes then it is a valid sub string because it contains only
1 odd char
*/

class Solution
{
public:
  // https://leetcode.com/problems/number-of-wonderful-substrings/?envType=daily-question&envId=2024-04-30
  long long wonderfulSubstrings(string word)
  {
    unordered_map<int, int> h;

    int mask = 0;
    h[0] = 1; // for all evens
    long long res = 0;

    for (int i = 0; i < word.size(); i++)
    {
      mask = mask ^ (1 << (word[i] - 'a'));
      res += h[mask];
      for (int i = 0; i < 10; i++)
      { // whenever we want to find the res from a specific index we do this technique
        if (h.find(mask ^ (1 << i)) != h.end())
        {
          res += h[mask ^ (1 << i)];
        }
      }
      h[mask]++;
    }

    return res;
  }
};