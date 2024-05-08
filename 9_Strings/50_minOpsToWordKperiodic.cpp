class Solution
{
public:
  // https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/
  int minimumOperationsToMakeKPeriodic(string word, int k)
  {
    unordered_map<string, int> hash;
    int maxi = -1e9;

    for (int i = 0; i <= word.size() - k; i += k)
    {
      maxi = max(maxi, ++hash[word.substr(i, k)]);
    }

    int prod = k * maxi;

    return (word.size() - prod) / k;
  }
};