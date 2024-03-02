class Solution
{
public:
  // https://leetcode.com/problems/minimize-deviation-in-array/description/
  int minimumDeviation(vector<int> &arr)
  {
    int n = arr.size();

    int mini = 1e9;
    int maxi = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] % 2 != 0)
      {
        arr[i] = arr[i] * 2;
      }
      mini = min(mini, arr[i]);
      maxi = max(maxi, arr[i]);
    }

    for (auto it : arr)
      pq.push(it);

    int top = 0;
    int min_dev = maxi - mini;
    while (pq.top() % 2 == 0)
    {
      top = pq.top();
      pq.pop();
      min_dev = min(min_dev, top - mini);
      mini = min(mini, top / 2);
      pq.push(top / 2);
    }
    top = pq.top();
    min_dev = min(min_dev, top - mini);
    return min_dev;
  }
};