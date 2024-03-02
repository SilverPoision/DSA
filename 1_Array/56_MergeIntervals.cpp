class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &arr)
  {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
      int k = i + 1;
      vector<int> temp = arr[i];
      while (k < n && temp[1] >= arr[k][0])
      {
        temp[1] = max(temp[1], arr[k][1]);
        k++;
      }

      ans.push_back(temp);
      i = k - 1;
    }

    return ans;
  }
};

// Same
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &arr)
  {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
      if (ans.empty() || ans.back()[1] < arr[i][0])
      {
        ans.push_back(arr[i]);
      }
      else
      {
        ans.back()[1] = max(ans.back()[1], arr[i][1]);
      }
    }

    return ans;
  }
};