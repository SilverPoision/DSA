class Solution
{
public:
  // Function to return the sorted array.
  vector<int> nearlySorted(int ans[], int n, int K)
  {
    // Your code here
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
      arr.push_back(ans[i]);
    }
    int j, key;

    for (int i = 1; i < n; i++)
    {
      key = arr[i];
      j = i - 1;

      while (j >= 0 && arr[j] > key)
      {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
      arr[j + 1] = key;
    }
    return arr;
  }
};

// Optimal
class Solution
{
public:
  // Function to return the sorted array.
  vector<int> nearlySorted(int arr[], int n, int k)
  {
    int size;
    size = (n == k) ? k : k + 1;
    priority_queue<int, vector<int>, greater<int>> min(arr, arr + size);

    int index = 0;

    for (int i = k + 1; i < n; i++)
    {
      arr[index++] = min.top();
      min.pop();
      min.push(arr[i]);
    }
    while (!min.empty())
    {
      arr[index++] = min.top();
      min.pop();
    }
    vector<int> ans(arr, arr + n);
    return ans;
  }
};