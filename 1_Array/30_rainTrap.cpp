#include <bits/stdc++.h>
using namespace std;

int storeWater(int arr[], int n)
{
  int left[n], right[n];
  left[0] = arr[0];
  int water = 0;
  for (int i = 1; i < n; i++)
  {
    left[i] = max(left[i - 1], arr[i]);
  }

  right[n - 1] = arr[n - 1];
  for (int i = n - 1; i >= 0; i--)
  {
    right[i] = max(right[i + 1], arr[i]);
  }

  for (int i = 1; i < n - 1; i++)
  {
    water += min(left[i], right[i]) - arr[i];
  }
  return water;
}

int main()
{
  int array1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int n = sizeof(array1) / sizeof(array1[0]);
  cout << "Maximum water that can be stored is "
       << storeWater(array1, n);
  return 0;
}

// optimal
class Solution
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();
    int leftMax = height[0];
    int rightMax = height[n - 1];
    int l = 1, r = n - 2;
    int sum = 0;

    while (l <= r)
    {
      if (leftMax < rightMax || leftMax == rightMax)
      {
        if (leftMax - height[l] > 0)
        {
          sum += leftMax - height[l];
        }
        leftMax = max(leftMax, height[l]);
        l++;
      }
      else if (leftMax > rightMax)
      {
        if (rightMax - height[r] > 0)
        {
          sum += rightMax - height[r];
        }
        rightMax = max(rightMax, height[r]);
        r--;
      }
    }
    return sum;
  }
};