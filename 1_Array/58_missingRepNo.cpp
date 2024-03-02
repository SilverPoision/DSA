// Optimal 1
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
  // Write your code here
  // see striver notes
  long long n = a.size();
  long long sn = (n * (n + 1)) / 2;                  // sum of n natural numbers
  long long sn2 = (n * (n + 1) * ((2 * n) + 1)) / 6; // sum of square of n natural numbers
  long long s = 0;
  long long s2 = 0;

  for (auto it : a)
  {
    s += it;       // sum of the arr
    s2 += it * it; // sum of the square of the eles of the arr
  }

  long long val1 = s - sn;
  long long val2 = s2 - sn2;
  val2 = val2 / val1;
  long long x = (val2 + val1) / 2;
  long long y = x - val1;

  return {(int)x, (int)y};
}

// Optimal 2
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
  // Write your code here
  int n = a.size();
  int xors = 0;
  for (int i = 0; i < n; i++)
  {
    xors ^= a[i];
    xors ^= (i + 1);
  }

  int cnt = 0;

  while (1)
  {
    if (xors & (1 << cnt))
    {
      break;
    }
    cnt++;
  }

  int zero = 0;
  int one = 0;

  for (auto it : a)
  {
    if (it & (1 << cnt))
    {
      one ^= it;
    }
    else
    {
      zero ^= it;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (i & (1 << cnt))
    {
      one ^= i;
    }
    else
    {
      zero ^= i;
    }
  }

  cnt = 0;
  for (auto it : a)
  {
    if (zero == it)
      cnt++;
  }

  if (cnt == 2)
    return {zero, one};
  else
    return {one, zero};
}

#include <bits/stdc++.h>

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
  // Write your code here
  int n = a.size();
  vector<int> hash(n + 1, 0);

  for (auto it : a)
  {
    hash[it]++;
  }

  int rep = -1, mis = -1;

  for (int i = 1; i <= n; i++)
  {
    if (hash[i] == 2)
    {
      rep = i;
    }
    else if (hash[i] == 0)
    {
      mis = i;
    }
    if (rep != -1 && mis != -1)
    {
      break;
    }
  }

  return {rep, mis};
}