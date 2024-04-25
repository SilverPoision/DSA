class Solution
{
public:
  bool isValid(int row, int col, vector<vector<char>> &board, int num)
  {
    for (int i = 0; i < board.size(); i++)
    {
      if (board[i][col] == num)
        return false;
      if (board[row][i] == num)
        return false;
      if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
        return false;
    }
    return true;
  }

  bool solve(vector<vector<char>> &board)
  {
    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board.size(); j++)
      {
        if (board[i][j] == '.')
        {
          for (char num = '1'; num <= '9'; num++)
          {
            if (isValid(i, j, board, num))
            {
              board[i][j] = num;
              if (solve(board))
                return true;
              else
                board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  void solveSudoku(vector<vector<char>> &board)
  {
    solve(board);
  }
};