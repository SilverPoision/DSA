class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    int cnt = 0;
    int lastEnd = intervals[0][1];

    for (int i = 1; i < n; i++)
    {
      if (intervals[i][0] >= lastEnd)
        lastEnd = intervals[i][1];
      else
      {
        lastEnd = min(lastEnd, intervals[i][1]);
        cnt++;
      }
    }

    return cnt;
  }
};