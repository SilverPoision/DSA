#include <cmath>

class Node
{
public:
  Node *child[2];

  void put(int x)
  {
    child[x] = new Node();
  }

  Node *get(int x)
  {
    return child[x];
  }

  bool containsKey(int x)
  {
    return child[x] != NULL;
  }
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
      if (!node->containsKey(bit))
      {
        node->put(bit);
      }
      node = node->get(bit);
    }
  }

  int maxNum(int x)
  {
    Node *node = root;
    int num = 0;
    for (int i = 31; i >= 0; i--)
    {
      int bit = (x >> i) & 1;
      if (node->containsKey(!bit))
      {
        node = node->get(!bit);
        num = num | (1 << i); // this will do the xor along. this will set the bits of the res
      }
      else
      {
        node = node->get(bit);
      }
    }

    return num;
  }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
  Trie t;
  for (auto it : arr1)
  {
    t.insert(it);
  }

  int maxi = 0;
  for (auto it : arr2)
  {
    maxi = max(maxi, t.maxNum(it));
  }

  return maxi;
}