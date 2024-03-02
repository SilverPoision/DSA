class Solution
{
public:
  vector<int> generateRow(int rowNo)
  {
    int ans = 1;
    vector<int> row;
    row.push_back(1);

    for (int col = 1; col < rowNo; col++)
    {
      ans = ans * (rowNo - col);
      ans = ans / (col);
      row.push_back(ans);
    }

    return row;
  }

  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> ans;

    for (int i = 1; i <= numRows; i++)
    {
      // vector<int> temp;
      ans.push_back(generateRow(i));
    }
    return ans;
  }
};