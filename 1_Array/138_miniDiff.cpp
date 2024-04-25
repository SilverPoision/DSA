class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/minimize-the-difference/1
  int minimizeDifference(int n, int k, vector<int> &arr)
  {
    // code here
    vector<pair<int, int>> suf(n), pre(n);

    suf[n - 1] = {arr[n - 1], arr[n - 1]};
    pre[0] = {arr[0], arr[0]};

    for (int i = 1; i < n; i++)
    {
      int revInd = n - 1 - i;
      pre[i] = {min(pre[i - 1].first, arr[i]), max(pre[i - 1].second, arr[i])};
      suf[revInd] = {min(suf[revInd + 1].first, arr[revInd]), max(suf[revInd + 1].second, arr[revInd])};
    }

    int ans = 1e9;

    for (int i = 0; i <= n; i++)
    {
      int mini = 1e9;
      int maxi = -1e9;

      int leftInd = i - 1;
      int rightInd = i + k;

      if (leftInd >= 0)
      {
        mini = min(mini, pre[leftInd].first);
        maxi = max(maxi, pre[leftInd].second);
      }

      if (rightInd < n)
      {
        mini = min(mini, suf[rightInd].first);
        maxi = max(maxi, suf[rightInd].second);
      }

      ans = min(ans, maxi - mini);
    }

    return ans;
  }
};

class Solution
{
public:
  int minimizeDifference(int n, int k, vector<int> &arr)
  {
    // code here
    map<int, int> hash;
    for (int i = k; i < n; i++)
      hash[arr[i]]++;

    int minDiff = abs(hash.begin()->first - hash.rbegin()->first);
    int ans = minDiff;

    for (int i = k; i < n; i++)
    {
      hash[arr[i - k]]++;
      hash[arr[i]]--;
      if (hash[arr[i]] == 0)
        hash.erase(arr[i]);
      minDiff = abs(hash.begin()->first - hash.rbegin()->first);
      ans = min(minDiff, ans);
    }

    return ans;
  }
};
