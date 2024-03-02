int minJumps(vector<int> &arr, int n)
{
  if (n == 1)
    return 0;

  int far = 0, curr = 0, c = 0;
  bool f = false;
  for (int i = 0; i < n - 1; i++)
  {
    far = max(far, i + arr[i]);
    if (i == curr)
    {
      curr = far;
      c++;
    }
    if (far >= n - 1)
      f = true;
  }
  if (f)
    return c;
  return -1;
}

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int n = nums.size();

    int l = 0, r = 0, res = 0;

    while (r < n - 1)
    {
      int far = 0;
      for (int i = l; i <= r; i++)
      {
        far = max(far, nums[i] + i);
      }

      l = r + 1;
      r = far;
      res++;
    }

    return res;
  }
};