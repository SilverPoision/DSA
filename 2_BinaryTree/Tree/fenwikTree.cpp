#include <iostream>
#include <bits/stdc++.h>

// Binary index tree
using namespace std;
// https://www.youtube.com/watch?v=9uaXG62Y8Uw

class FenwikTree
{
public:
  vector<int> fen;
  int N;

  FenwikTree(int n)
  {
    this->N = n + 1;
    fen.resize(this->N, 0);
  }

  void update(int i, int add)
  {
    while (i < N)
    {
      this->fen[i] += add;
      i += i & (-i);
    }
  }

  int sum(int i)
  {
    int s = 0;

    while (i > 0)
    {
      s += this->fen[i];
      i -= (i & (-i));
    }

    return s;
  }

  int range(int l, int r)
  {
    return sum(r) - sum(l - 1);
  }

  int lower_bound(int k)
  {
    int ans = 0, curr = 0, prevSum = 0;
    for (int i = log2(N); i >= 0; i--)
    {
      if (fen[curr + (1 << i)] + prevSum < k)
      {
        curr = curr + (1 << i);
        prevSum += fen[curr];
      }
    }

    return curr + 1;
  }
};

int main()
{
  vector<int> arr = {
      1,
      0,
      2,
      1,
      1,
      3, 0, 4, 2, 5, 2, 2, 3, 1, 0, 2};
  FenwikTree f(arr.size());

  for (int i = 0; i < arr.size(); i++)
  {
    f.update(i + 1, arr[i]);
  }

  // f.update(1, 5);

  cout << f.sum(3) << endl;
  cout << f.lower_bound(27);
  return 0;
}