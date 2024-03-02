class Solution
{
public:
  int getLastMoment(int n, vector<int> &left, vector<int> &right)
  {
    int min = right.size() > 0 ? *min_element(right.begin(), right.end()) : n;
    int maxi = left.size() > 0 ? *max_element(left.begin(), left.end()) : 0;

    return max((n - min), maxi);
  }
};