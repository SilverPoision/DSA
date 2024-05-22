class Solution
{
public:
  // https://leetcode.com/problems/k-th-smallest-prime-fraction/editorial/
  // https://www.youtube.com/watch?v=SmxdebjWvfs
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
  {
    int n = arr.size();
    double left = 0, right = 1.0;

    // Binary search for finding the kth smallest prime fraction
    while (left < right)
    {
      // Calculate the middle value
      double mid = (left + right) / 2;

      // Initialize variables to keep track of maximum fraction and indices
      double maxFraction = 0.0;
      int totalSmallerFractions = 0, numeratorIdx = 0, denominatorIdx = 0;
      int j = 1;

      // Iterate through the array to find fractions smaller than mid
      for (int i = 0; i < n - 1; i++)
      {
        while (j < n && arr[i] >= mid * arr[j])
        {
          j++;
        }

        // Count smaller fractions
        totalSmallerFractions += (n - j);

        // If we have exhausted the array, break
        if (j == n)
          break;

        // Calculate the fraction
        double fraction = static_cast<double>(arr[i]) / arr[j];

        // Update maxFraction and indices if necessary
        if (fraction > maxFraction)
        {
          numeratorIdx = i;
          denominatorIdx = j;
          maxFraction = fraction;
        }
      }

      // Check if we have found the kth smallest prime fraction
      if (totalSmallerFractions == k)
      {
        return {arr[numeratorIdx], arr[denominatorIdx]};
      }
      else if (totalSmallerFractions > k)
      {
        right = mid; // Adjust the range for binary search
      }
      else
      {
        left = mid; // Adjust the range for binary search
      }
    }
    return {}; // Return empty vector if kth smallest prime fraction not found
  }
};

class Solution
{
public:
  typedef pair<double, pair<int, int>> v;
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
  {
    int n = arr.size();
    priority_queue<v, vector<v>, greater<v>> pq;

    for (int i = 0; i < n - 1; i++)
    {
      pq.push({1.0 * arr[i] / arr[n - 1], {(double)(i), (double)(n - 1)}});
    }

    int smallest = 1;
    while (smallest < k)
    {
      v top = pq.top();
      pq.pop();

      int i = top.second.first;
      int j = top.second.second - 1;

      pq.push({(double)arr[i] / arr[j], {(double)i, (double)j}});
      smallest++;
    }

    auto vec = pq.top().second;
    int i = vec.first;
    int j = vec.second;

    return {arr[i], arr[j]};
  }
};