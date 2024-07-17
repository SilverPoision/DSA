class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/three-sum-closest/1
  int threeSumClosest(vector<int> arr, int target)
  {
    // Your code goes here
    int n = arr.size();
    int ans = 0;
    int sum = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i <= n - 3; i++)
    {
      int l = i + 1, r = n - 1;

      while (l < r)
      {
        int currSum = arr[i] + arr[l] + arr[r];
        int rem = abs(target - currSum);

        if (currSum == target)
          return currSum;
        else if (ans == 0 || rem < ans)
        {
          sum = currSum;
          ans = rem;
        }
        else if (ans == rem && currSum > sum)
        {
          sum = currSum;
        }

        if (currSum > target)
          r--;
        else
          l++;
      }
    }

    return sum;
  }
};