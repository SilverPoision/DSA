class Solution
{
public:
  // https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16
  int maxDistance(vector<vector<int>> &arr)
  {
    int n = arr.size();

    int currMin = arr[0][0], currMax = arr[0].back();
    int res = 0;

    for (int i = 1; i < n; i++)
    {
      vector<int> a = arr[i];

      res = max({res, a.back() - currMin, currMax - a[0]});

      currMin = min(currMin, a[0]);
      currMax = max(currMax, a.back());
    }

    return res;
  }
};

class Solution
{
public:
  typedef pair<int, int> pii;
  int maxDistance(vector<vector<int>> &arr)
  {
    int n = arr.size();

    priority_queue<pii> maxi;
    priority_queue<pii, vector<pii>, greater<pii>> mini;

    int i = 0;
    for (auto it : arr)
    {
      maxi.push({it.back(), i});
      mini.push({it[0], i});
      i++;
    }

    if (mini.top().second == maxi.top().second)
    {
      pii m = mini.top();
      mini.pop();
      int res = maxi.top().first - mini.top().first;
      mini.push(m);

      m = maxi.top();
      maxi.pop();
      res = max(res, maxi.top().first - mini.top().first);
      maxi.push(m);

      return res;
    }

    return maxi.top().first - mini.top().first;
  }
};