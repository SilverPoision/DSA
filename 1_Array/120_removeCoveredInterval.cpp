class Solution
{
public:
  static bool comp(const vector<int> &a, const vector<int> &b)
  {
    if (a[0] != b[0])
      return a[0] < b[0];
    return a[1] > b[1];
  }
  int removeCoveredIntervals(vector<vector<int>> &intv)
  {
    sort(intv.begin(), intv.end(), comp);
    int seeI = 0;
    int cnt = 1;
    for (int i = 1; i < intv.size(); i++)
    {
      if (intv[seeI][0] > intv[i][0] || intv[seeI][1] < intv[i][1])
      {
        seeI = i;
        cnt++;
      }
    }

    return cnt;
  }
};

class Solution
{
public:
  static bool comp(vector<int> a, vector<int> b)
  {
    if (a[0] == b[0])
      return a[1] > b[1];
    return a[0] < b[0];
  }
  int removeCoveredIntervals(vector<vector<int>> &intv)
  {
    sort(intv.begin(), intv.end(), comp);
    vector<vector<int>> temp;
    temp.push_back(intv[0]);
    for (int i = 1; i < intv.size(); i++)
    {
      if (temp.back()[0] > intv[i][0] || temp.back()[1] < intv[i][1])
      {
        temp.push_back(intv[i]);
      }
    }

    return temp.size();
  }
};