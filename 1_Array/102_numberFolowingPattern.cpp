class Solution
{
public:
  // https://leetcode.com/problems/construct-smallest-number-from-di-string/description/
  void rev(vector<int> &s, int i, int j)
  {
    while (i < j)
    {
      swap(s[i], s[j]);
      j--;
      i++;
    }
    return;
  }
  string smallestNumber(string s)
  {
    int size = s.size() + 1;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
      arr[i] = i + 1;
    }

    for (int i = 0; i < s.size(); i++)
    {
      int temp = i;

      while (temp < s.size() && s[temp] == 'D')
        temp++;

      if (i < temp)
        rev(arr, i, temp);
      i = temp;
    }

    string ans;
    for (auto it : arr)
    {
      ans += to_string(it);
    }

    return ans;
  }
};