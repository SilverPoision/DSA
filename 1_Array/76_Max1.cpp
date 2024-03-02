class Solution
{
public:
  int longestOnes(vector<int> &arr, int k)
  {
    int n = arr.size();
    int i = 0, j = 0;
    int maxi = 0;
    int t = k;

    while (i < n && j < n)
    {
      if (arr[j] == 1 || t > 0)
      {
        if (arr[j] == 0)
          t--;
        maxi = max(maxi, j - i + 1);
        j++;
      }
      else
      {
        while (arr[i] != 0 && i <= j)
        {
          i++;
        }
        t++;
        i++;
      }
    }

    return maxi;
  }
};