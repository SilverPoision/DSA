class Solution
{
public:
  int mod = 1e9 + 7;
  void findLR(vector<int> &arr, vector<long long> &left, vector<long long> &right, int n)
  {
    stack<pair<int, int>> stl;
    stack<pair<int, int>> str;

    for (int i = 0; i < n; i++)
    {
      int curr = arr[i];
      int cnt = 1;
      while (!stl.empty() && curr < stl.top().first)
      {
        cnt += stl.top().second;
        stl.pop();
      };

      stl.push({curr, cnt});
      left[i] = cnt;
    }

    for (int i = n - 1; i >= 0; i--)
    {
      int curr = arr[i];
      int cnt = 1;
      while (!str.empty() && curr <= str.top().first)
      { // <= because for same ele we have to take it from one side either from right or left
        cnt += str.top().second;
        str.pop();
      };

      str.push({curr, cnt});
      right[i] = cnt;
    }
  }

  int sumSubarrayMins(vector<int> &arr)
  {
    int n = arr.size();
    vector<long long> left(n);
    vector<long long> right(n);

    findLR(arr, left, right, n);

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += (arr[i] * left[i] * right[i]) % mod;
    }

    return sum % mod;
  }
};