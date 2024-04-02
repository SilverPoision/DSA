class Solution
{
public:
  void inorder(Node *root, vector<int> &in)
  {
    if (!root)
      return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
  }

  int merge(vector<int> &arr, int low, int mid, int high)
  {
    vector<int> temp;
    int inC = 0;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
      if (arr[i] > arr[j])
      {
        inC += (mid - i + 1);
        temp.push_back(arr[j++]);
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

    for (int l = low; l <= high; l++)
    {
      arr[l] = temp[l - low];
    }

    return inC;
  }

  int mergeSort(vector<int> &arr, int low, int high)
  {
    int inC = 0;
    if (low >= high)
      return inC;

    int mid = low + (high - low) / 2;
    inC += mergeSort(arr, low, mid);
    inC += mergeSort(arr, mid + 1, high);
    inC += merge(arr, low, mid, high);

    return inC;
  }

  /*You are required to complete below function */
  int pairsViolatingBST(int n, Node *root)
  {
    // your code goes here
    vector<int> in;
    inorder(root, in);

    return mergeSort(in, 0, in.size() - 1);
  }
};