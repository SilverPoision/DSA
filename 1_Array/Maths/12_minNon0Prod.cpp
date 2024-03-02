#define ll long long

class Solution
{
public:
  int mod = 1e9 + 7;
  int minNonZeroProduct(int p)
  {
    ll val = pow(2, p);
    val--;

    ll k = (val - 1) / 2;
    ll n = val - 1;

    ll res = expn(n, k);
    return res * ((val) % mod) % mod;
  }

  ll expn(ll num, ll p)
  {
    if (p == 0)
      return 1;
    if (p == 1)
      return num % mod;

    ll res = expn(num, p / 2);
    if (p % 2 == 0)
    {
      return (res * res) % mod;
    }
    return (((res * res) % mod) * (num % mod)) % mod;
  }
};