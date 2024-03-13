class Solution
{
public:
  // https://leetcode.com/problems/bag-of-tokens/
  int bagOfTokensScore(vector<int> &to, int power)
  {
    sort(to.begin(), to.end());

    int i = 0, j = to.size() - 1;
    int score = 0, maxScore = 0;

    while (i <= j)
    {
      if (to[i] <= power)
      {
        power -= to[i++];
        score++;
        maxScore = max(score, maxScore);
      }
      else if (score > 0)
      {
        power += to[j--];
        score--;
      }
      else
      {
        break;
      }
    }

    return maxScore;
  }
};