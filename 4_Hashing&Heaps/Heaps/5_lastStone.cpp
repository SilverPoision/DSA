/*
1046. Last Stone Weight
Easy
4.2K
80
Companies
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.



Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
*/

class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    make_heap(stones.begin(), stones.end());
    while (stones.size() > 1)
    {
      int y = stones.front();
      pop_heap(stones.begin(), stones.end());
      stones.pop_back();
      int x = stones.front();
      pop_heap(stones.begin(), stones.end());
      stones.pop_back();
      if (x == y)
      {
        continue;
      }
      else
      {
        int res = y - x;
        stones.push_back(res);
        push_heap(stones.begin(), stones.end());
      }
    }
    return stones.size() == 1 ? stones[0] : 0;
  }
};

// Same as above but diff implementation

class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {

    priority_queue<int> max_heap;
    int n = stones.size();

    for (int i = 0; i < n; ++i)
      max_heap.push(stones[i]);

    int first, second;
    while (n > 1)
    {
      first = max_heap.top();
      max_heap.pop();
      second = max_heap.top();
      max_heap.pop();
      n -= 2;

      if (first - second > 0)
      {
        max_heap.push(first - second);
        n += 1;
      }
    }

    if (!max_heap.empty())
      return max_heap.top();
    return 0;
  }
};