#include <bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
  // Write your code here
  int n = str.size();
  int i = 0, j = 0;
  int ans = 0;

  map<char, int> hash;

  while (j < n)
  {
    hash[str[j]]++;

    while (hash.size() > k)
    {
      hash[str[i]]--;
      if (hash[str[i]] == 0)
        hash.erase(str[i]);
      i++;
    }

    ans = max(ans, j - i + 1);

    j++;
  }

  return ans;
}
