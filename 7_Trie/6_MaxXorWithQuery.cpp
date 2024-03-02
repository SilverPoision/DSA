class Node
{
public:
  Node *child[2];
};

class Trie
{
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }

  void insert(int x)
  {
    Node *node = root;
    for (int i = 31; i >= 0; i--)
    {
      int bit = (x >> i) & 1;
      if (!node->child[bit])
        node->child[bit] = new Node();
      node = node->child[bit];
    }
  }

  int getMax(int x)
  {
    Node *node = root;
    int num = 0;
    for (int i = 31; i >= 0; i--)
    {
      int bit = (x >> i) & 1;
      if (node->child[!bit])
      {
        num = num | (1 << i);
        node = node->child[!bit];
      }
      else
      {
        node = node->child[bit];
      }
    }
    return num;
  }
};

class Solution
{
public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &q)
  {
    vector<pair<int, pair<int, int>>> mem;
    Trie t;
    for (int i = 0; i < q.size(); i++)
    {
      mem.push_back({q[i][1], {q[i][0], i}});
    }
    sort(nums.begin(), nums.end());
    sort(mem.begin(), mem.end());

    vector<int> ans(q.size(), 0);
    int i = 0;

    for (auto it : mem)
    {
      int q = it.second.first;
      int limit = it.first;
      for (i; i < nums.size(); i++)
      {
        if (nums[i] <= limit)
        {
          t.insert(nums[i]);
        }
        else
        {
          break;
        }
      }
      if (i != 0)
        ans[it.second.second] = t.getMax(q);
      else
        ans[it.second.second] = -1;
    }

    return ans;
  }
};