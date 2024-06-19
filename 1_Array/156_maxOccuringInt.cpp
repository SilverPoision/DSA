int maxOccured(int n, int l[], int r[], int maxx)
{
  // https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1
  // https://www.youtube.com/watch?v=MDeavLUJVD0
  //  intution is to calculate
  //  prefix sum of frequency array ...
  vector<int> freq(maxx + 2, 0);

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    freq[l[i]]++;
    freq[r[i] + 1]--;
  }

  for (int i = 1; i <= maxx; i++)
  {
    freq[i] += freq[i - 1];

    if (freq[i] > freq[ans])
      ans = i;
  }

  return ans;
}