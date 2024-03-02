class Solution
{
public:
  bool validMountainArray(vector<int> &arr)
  {
    int n = arr.size();
    if (n < 3)
      return false;

    bool flag = false;
    bool flag2 = false;
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i] < arr[i + 1] && !flag2)
      {
        flag = true;
      }
      else if (arr[i] > arr[i + 1] && flag)
      {
        flag2 = true;
      }
      else
      {
        return false;
      }
    }
    return flag2;
  }
};

// Both are same
class Solution
{
public:
  bool validMountainArray(vector<int> &arr)
  {
    int i = 1;
    int n = arr.size();
    while (i < n && arr[i] > arr[i - 1])
    {
      i++;
    }
    if (i == 1 || i == n)
      return false;
    while (i < n && arr[i] < arr[i - 1])
    {
      i++;
    }
    return i == n;
  }
};