class Solution
{
public:
  // https://leetcode.com/problems/random-flip-matrix/
  unordered_map<int, bool> hash;
  long long total_num;
  int n;
  Solution(int m, int n)
  {
    total_num = n * m;
    this->n = n;
  }

  vector<int> flip()
  {
    int rand_int = rand() % this->total_num;
    int row = rand_int / n;
    int col = rand_int % n;
    while (hash.find(rand_int) != hash.end())
    {
      rand_int = rand() % this->total_num;
      row = rand_int / n;
      col = rand_int % n;
    }

    hash[rand_int] = true;

    return {row, col};
  }

  void reset()
  {
    hash.clear();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */