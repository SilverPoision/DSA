// Sieve of eratosthenes

class Solution
{
public:
  int countPrimes(int n)
  {
    if (n == 0 || n == 1)
      return 0;

    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
      if (!isPrime[i])
        continue;
      for (int j = i * i; j < n; j += i)
      {
        isPrime[j] = false;
      }
    }

    int cnt = 0;
    for (auto it : isPrime)
      if (it)
        cnt++;

    return cnt;
  }
};

vector<int> countPrimes(int n)
{
  // Write your code here.
  vector<bool> divisibles(n, false);

  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
      divisibles[i] = true;
  }

  for (int i = 2; i * i < n; i++)
  {
    if (!divisibles[i])
      continue;

    for (int j = i * i; j < n; j += i)
    {
      divisibles[j] = false;
    }
  }

  vector<int> ans;

  for (int i = 0; i < n; i++)
  {
    if (divisibles[i] == true)
      ans.push_back(i);
  }

  return ans;
}