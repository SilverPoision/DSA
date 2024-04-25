class Solution
{
public:
  vector<int> secondGreaterElement(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> s1, s2, temp, res(n, -1);

    for (int i = 0; i < n; i++)
    {
      while (!s2.empty() && nums[s2.back()] < nums[i])
      {
        res[s2.back()] = nums[i];
        s2.pop_back();
      }
      while (!s1.empty() && nums[s1.back()] < nums[i])
      {
        temp.push_back(s1.back()); // to maintian the relative order in the stack
        s1.pop_back();
      }
      while (!temp.empty())
      {
        s2.push_back(temp.back());
        temp.pop_back();
      }
      s1.push_back(i);
    }

    return res;
  }
};