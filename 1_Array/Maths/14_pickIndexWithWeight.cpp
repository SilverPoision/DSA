class Solution
{
public:
  vector<int> cSum;
  Solution(vector<int> &w)
  {
    cSum.push_back(w[0]);
    for (int i = 1; i < w.size(); i++)
    {
      cSum.push_back(cSum.back() + w[i]);
    }
  }

  int pickIndex()
  {
    int randWeight = rand() % (cSum.back());
    return upper_bound(cSum.begin(), cSum.end(), randWeight) - cSum.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */