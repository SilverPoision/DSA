class Solution
{
public:
  bool isSafe(vector<string> &board, int row, int col)
  {
    int n = size(board);
    for (int i = 0; i < n; i++)
    {
      // checking if there is a queen in the same column
      if (board[i][col] == 'Q')
        return false;
      // checking if there is a queen in the same diagonal (left to right)
      if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q')
        return false;
      if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q')
        return false;
      // No need to traverse more since the lower rows below current row attribute will always be safe.
      /* if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
      if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; */
    }
    return true;
  }

  void solve(int i, vector<string> &board, vector<vector<string>> &out)
  {
    if (i >= board.size())
    {
      out.push_back(board);
      return;
    }

    for (int j = 0; j < board.size(); j++)
    {
      if (isSafe(board, i, j))
      {
        board[i][j] = 'Q';
        solve(i + 1, board, out);
        board[i][j] = '.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans);
    return ans;
  }
};