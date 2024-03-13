class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
  //  The main function that returns the arrangement with the largest value as
  //  string.
  //  The function accepts a vector of strings
  static bool cmp(string x, string y)
  {
    if (x + y > y + x)
      return true;
    return false;
  }
  string printLargest(int n, vector<string> &arr)
  {
    // code here
    sort(arr.begin(), arr.end(), cmp);
    string ans = "";
    for (auto it : arr)
      ans += it;
    return ans;
  }
};