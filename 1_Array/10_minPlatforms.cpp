int calculateMinPatforms(int at[], int dt[], int n)
{
  // Write your code here.
  sort(dt, dt + n);
  sort(at, at + n);

  int i = 1, j = 0;
  int plat = 1;
  int maxi = 1;

  while (i < n && j < n)
  {
    if (at[i] <= dt[j])
    {
      plat++;
      maxi = max(maxi, plat);
      i++;
    }
    else
    {
      plat--;
      j++;
    }
  }

  return maxi;
}