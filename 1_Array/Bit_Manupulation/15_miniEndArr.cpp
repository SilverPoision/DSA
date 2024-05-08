class Solution
{
public:
  // https://leetcode.com/problems/minimum-array-end/
  // https://www.youtube.com/watch?v=eA1xIDUqIDc
  typedef long long ll;
  ll minEnd(int n, int x)
  {
    n--;
    vector<ll> xBit(64, 0);
    vector<ll> nBit(64, 0);

    for (int i = 0; i < 32; i++)
    {
      xBit[i] = (x >> i) & 1;
      nBit[i] = (n >> i) & 1;
    }

    int i = 0, j = 0;
    while (i < 64)
    {
      if (xBit[i] == 1)
      {
        i++;
        continue;
      }

      xBit[i++] = nBit[j++];
    }

    ll ans = 0;
    for (int i = 63; i >= 0; i--)
    {
      ans = (ans * 2) + xBit[i];
    }

    return ans;
  }
};