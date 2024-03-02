class Solution
{
public:
  // without map
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    sort(hand.begin(), hand.end());
    for (int i = 0; i < hand.size(); i++)
    {
      if (hand[i] == -1)
        continue;
      int curr = hand[i];
      int temp = 1;
      for (int j = i + 1; j < hand.size() && temp < groupSize; j++)
      {
        if (hand[j] > curr + 1)
          break;
        if (hand[j] == curr + 1)
        {
          hand[j] = -1;
          curr++;
          temp++;
        }
      }
      if (temp != groupSize)
        return false;
    }
    return true;
  }
};

class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int k)
  {
    if (hand.size() % k)
      return false;

    map<int, int> hash;

    for (auto it : hand)
    {
      hash[it]++;
    }

    while (!hash.empty())
    {
      int curr = hash.begin()->first;
      for (int i = curr; i < curr + k; i++)
      {
        if (hash.find(i) == hash.end())
          return false;
        hash[i]--;
        if (hash[i] == 0)
          hash.erase(i);
      }
    }

    return true;
  }
};