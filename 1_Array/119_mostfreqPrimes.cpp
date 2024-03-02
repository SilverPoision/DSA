class Solution
{
public:
  bool isPrime(int num)
  {
    for (int i = 2; i * i <= num; i++)
    {
      if (num % i == 0)
        return false;
    }

    return true;
  }
  vector<int> row = {0, 0, 1, -1, 1, 1, -1, -1};
  vector<int> col = {1, -1, 0, 0, 1, -1, 1, -1};
  int mostFrequentPrime(vector<vector<int>> &mat)
  {

    int n = mat.size();
    int m = mat[0].size();

    unordered_map<int, int> hash;
    int w = 0;

    for (int i = 0; i < n; i++)
    {

      for (int j = 0; j < m; j++)
      {

        for (int k = 0; k < 8; k++)
        {
          int temp = mat[i][j];
          if (temp > 10 && isPrime(temp))
            w = max(w, ++hash[temp]);
          int r = i + row[k];
          int c = j + col[k];

          while (r < n && c < m && r >= 0 && c >= 0)
          {
            temp = (temp * 10) + mat[r][c];
            if (temp > 10 && isPrime(temp))
              w = max(w, ++hash[temp]);
            r += row[k];
            c += col[k];
          }
        }
      }
    }

    int maxi = -1;
    for (auto it : hash)
    {
      if (it.second == w)
      {
        maxi = max(maxi, it.first);
      }
    }

    return maxi;
  }
};