class Solution
{
public:
  // More optimal but both are almost same
  // https://leetcode.com/problems/longest-turbulent-subarray/
  int maxTurbulenceSize(vector<int> &arr)
  {
    if (arr.size() == 1)
      return 1;

    int l = 0;
    int r = 1;
    int windowSize = 1;
    char prev = ' ';
    // true its going down
    //  false its going up
    while (r < arr.size())
    {
      if (arr[r - 1] > arr[r] && prev != '>')
      {
        r++;
        prev = '>';
        windowSize = max(windowSize, r - l);
      }
      else if (arr[r - 1] < arr[r] && prev != '<')
      {
        r++;
        prev = '<';
        windowSize = max(windowSize, r - l);
      }
      else
      {
        if (arr[r - 1] == arr[r])
        {
          r = r + 1;
        }
        l = r - 1;
        prev = ' ';
      }
    }
    return windowSize;
  }
};

class Solution
{
public:
  int maxTurbulenceSize(vector<int> &arr)
  {
    int n = arr.size();
    if (arr.size() == 1)
      return 1;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      if (ans > n - i + 1)
        break;
      bool flag = true;
      int cnt = 0;
      for (int j = i; j < n - 1; j++)
      {
        if (arr[j] > arr[j + 1])
        {
          if (flag)
            cnt++;
          else
            break;
          flag = !flag;
        }
        else if (arr[j] < arr[j + 1])
        {
          if (!flag || j == i)
            cnt++;
          else
            break;
          if (j != i)
            flag = !flag;
        }
        else
          break;
      }
      ans = max(cnt, ans);
    }

    return ans + 1;
  }
};