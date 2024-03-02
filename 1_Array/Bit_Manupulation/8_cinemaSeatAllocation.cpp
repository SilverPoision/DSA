class Solution
{
public:
  // https://leetcode.com/problems/cinema-seat-allocation/description/comments/1567465
  int maxNumberOfFamilies(int n, vector<vector<int>> &rs)
  {
    unordered_map<int, char> hash;

    for (int i = 0; i < rs.size(); i++)
    {
      int row = rs[i][0] - 1;
      int col = rs[i][1];

      if (hash.find(row) == hash.end())
        hash[row] = 7;

      if (col == 2 || col == 3)
        hash[row] &= 3;
      else if (col == 4 || col == 5)
        hash[row] &= 1;
      else if (col == 6 || col == 7)
        hash[row] &= 4;
      else if (col == 8 || col == 9)
        hash[row] &= 6;
    }

    int res = (n - hash.size()) * 2;

    for (auto it : hash)
    {
      if (it.second == 5 || it.second == 7)
        res += 2;
      else if (it.second != 0)
        res += 1;
    }

    return res;
  }
};

class Solution
{
public:
  // 3 4 3
  // 4- 11|11 or 1111
  // 發現 unordered_map<int,int> 會 Memory Limit Exceeded ...
  // 改用 vector<char> 還是會 Memory Limit Exceeded ...
  int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
  {
    unordered_map<int, char> masks;
    for (int i = 0; i < reservedSeats.size(); i++)
    {
      int row = reservedSeats[i][0];
      int col = reservedSeats[i][1];
      if (col > 1 && col < 10)
        masks[row - 1] |= (1 << (col - 2));
    }
    int max_seat = n * 2;
    int res = 0;
    for (auto &[row, seat] : masks)
    {
      // 11-11 優先 在來 1111
      // 算出不能做的seats
      bool left = seat & 0b11110000;
      bool right = seat & 0b00001111;
      bool mid = seat & 0b00111100;
      res += left && right && mid ? 2 : 1;
    }
    return max_seat - res;
  }
};