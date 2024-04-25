class Solution
{
public:
  // https://leetcode.com/problems/reveal-cards-in-increasing-order/?envType=daily-question&envId=2024-04-10
  vector<int> deckRevealedIncreasing(vector<int> &deck)
  {
    if (deck.size() < 3)
      return deck;

    sort(deck.begin(), deck.end(), greater<int>());
    vector<int> ans;

    queue<int> q;
    q.push(deck[0]);
    q.push(deck[1]);

    for (int i = 2; i < deck.size(); i++)
    {
      q.push(q.front());
      q.pop();
      q.push(deck[i]);
    }

    while (!q.empty())
    {
      ans.push_back(q.front());
      q.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};