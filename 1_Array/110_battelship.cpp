class Solution
{
public:
  // https://leetcode.com/problems/battleships-in-a-board/
  // https://www.youtube.com/watch?v=74NuFEdzs6A
  int countBattleships(vector<vector<char>> &board)
  {
    int n = board.size();
    int m = board[0].size();

    int cnt = 0;
    int top, left;

    for (int i = 0; i < n; i++)
    {
      top = i - 1;
      for (int j = 0; j < m; j++)
      {
        left = j - 1;
        if (board[i][j] == 'X' && (top < 0 || board[top][j] == '.') && (left < 0 || board[i][left] == '.'))
        {
          cnt++;
        }
      }
    }

    return cnt;
  }
};