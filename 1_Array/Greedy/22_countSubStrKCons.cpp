class Solution
{
public:
  // https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/
  vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &q)
  {
    int n = s.size();

    vector<int> leftMost(n, 0), rightMost(n, 0);
    unordered_map<char, int> hash;

    int i = 0, j = 0;

    while (j < n)
    {
      hash[s[j]]++;

      while (hash['0'] > k && hash['1'] > k)
      {
        hash[s[i]]--;
        i++;
      }

      leftMost[j] = i;
      j++;
    }

    hash.clear();
    i = n - 1, j = n - 1;

    while (j >= 0)
    {
      hash[s[j]]++;

      while (hash['0'] > k && hash['1'] > k)
      {
        hash[s[i]]--;
        i--;
      }

      rightMost[j] = i;
      j--;
    }

    vector<long long> tempSubstr(n, 0), cumsum(n, 0);

    for (int j = 0; j < n; j++)
    {
      tempSubstr[j] = j - leftMost[j] + 1;
    }

    cumsum[0] = tempSubstr[0];
    for (int j = 1; j < n; j++)
    {
      cumsum[j] = cumsum[j - 1] + tempSubstr[j];
    }

    vector<long long> ans;
    for (auto it : q)
    {
      int low = it[0];
      int high = it[1];

      int rightValidIDX = min(high, rightMost[low]);
      long long len = rightValidIDX - low + 1;

      long long res = len * (len + 1) / 2;

      res += cumsum[high] - cumsum[rightValidIDX];

      ans.push_back(res);
    }

    return ans;
  }
};
