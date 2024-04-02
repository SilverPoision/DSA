int merge(vector<int> &arr, int low, int high, int mid)
{
  int i = low, j = mid + 1;
  vector<int> temp;
  int inversion = 0;

  while (i <= mid && j <= high)
  {
    if (arr[i] > arr[j])
    {
      temp.push_back(arr[j++]);
      inversion += (mid - i + 1); // because all the ele in the right of the ele
      // will also be greater than the element at i so we take count of all
      // the ele after i
    }
    else
    {
      temp.push_back(arr[i++]);
    }
  }

  while (i <= mid)
  {
    temp.push_back(arr[i++]);
  }
  while (j <= high)
  {
    temp.push_back(arr[j++]);
  }

  for (int ind = low; ind <= high; ind++)
  {
    arr[ind] = temp[ind - low];
  }

  return inversion;
}
int mergeSort(vector<int> &arr, int low, int high)
{
  int inversion = 0;
  if (low < high)
  {
    int mid = (low + high) / 2;

    inversion += mergeSort(arr, low, mid);
    inversion += mergeSort(arr, mid + 1, high);
    inversion += merge(arr, low, high, mid);
  }

  return inversion;
}

int numberOfInversions(vector<int> &a, int n)
{
  // Write your code here.
  return mergeSort(a, 0, n - 1);
}