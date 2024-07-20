class Solution
{
public:
  vector<int> ans;
  // https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1
  void merge(vector<pair<int, int>> &arr, int low, int mid, int high)
  {
    int i = low, j = mid + 1;
    vector<pair<int, int>> res;
    while (i <= mid && j <= high)
    {
      if (arr[i].first > arr[j].first)
      {
        ans[arr[i].second] += high - j + 1;
        res.push_back(arr[i++]);
      }
      else
      {
        res.push_back(arr[j++]);
      }
    }

    while (i <= mid)
    {
      res.push_back(arr[i++]);
    }
    while (j <= high)
    {
      res.push_back(arr[j++]);
    }

    for (int ind = low; ind <= high; ind++)
    {
      arr[ind] = res[ind - low];
    }
  }
  void mergeSort(vector<pair<int, int>> &arr, int l, int h)
  {
    if (l < h)
    {
      int mid = (l + h) / 2;
      mergeSort(arr, l, mid);
      mergeSort(arr, mid + 1, h);
      merge(arr, l, mid, h);
    }
  }

  vector<int> constructLowerArray(vector<int> &arr)
  {
    // code here
    int n = arr.size();
    ans.resize(n, 0);

    vector<pair<int, int>> ar1;
    for (int i = 0; i < n; i++)
    {
      ar1.push_back({arr[i], i});
    }

    mergeSort(ar1, 0, n - 1);

    return ans;
  }
};

// Fenwick

vector<int> bit;
int n;
int sum(int ind)
{
  int ans = 0;

  while (ind > 0)
  {
    ans += bit[ind];
    ind -= (ind & (-ind));
  }

  return ans;
}
void update(int ind)
{
  while (ind <= n)
  {
    bit[ind] += 1;
    ind += (ind & (-ind));
  }
}
vector<int> constructLowerArray(vector<int> &arr)
{
  // code here
  this->n = arr.size();
  bit.resize(n + 1, 0);
  vector<int> ans(n);

  vector<pair<int, int>> ar1;

  for (int i = 0; i < n; i++)
  {
    ar1.push_back({arr[i], i});
  }

  sort(ar1.begin(), ar1.end());

  for (auto it : ar1)
  {
    update(it.second + 1);
    ans[it.second] = sum(n) - sum(it.second + 1);
  }

  return ans;
}