class Solution
{
  // https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
  // https://www.youtube.com/watch?v=8kwPXbTMSnk
public:
  int num_pts;
  vector<vector<int>> rects;
  vector<int> rect_cum;
  Solution(vector<vector<int>> &rects)
  {
    this->rects = rects;
    num_pts = 0;
    for (auto rect : rects)
    {
      num_pts += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
      rect_cum.push_back(num_pts);
    }
  }

  vector<int> pick()
  {
    int r_ind = rand() % num_pts;

    int l = 0, r = rects.size() - 1;
    while (l < r)
    {
      int mid = l + (r - l) / 2;

      if (rect_cum[mid] <= r_ind)
        l = mid + 1;
      else
        r = mid;
    }

    vector<int> rect = rects[l];

    int rect_width = rect[2] - rect[0] + 1;
    int rect_height = rect[3] - rect[1] + 1;

    int rect_pts = rect_width * rect_height;
    int rect_start = rect_cum[l] - rect_pts;

    int offset = r_ind - rect_start;

    return {rect[0] + (offset % rect_width), rect[1] + (offset / rect_width)};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */