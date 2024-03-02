#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  char data;
  TrieNode *child[26];
  bool isTerminal;

  TrieNode(char data)
  {
    this->data = data;
    for (int i = 0; i < 26; i++)
    {
      child[i] = nullptr;
    }
    isTerminal = 0;
  }
};

class Trie
{
public:
  TrieNode *root;

  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    // present
    if (root->child[index] != NULL)
    {
      child = root->child[index];
    }
    else
    {
      // absent
      child = new TrieNode(word[0]);
      root->child[index] = child;
    }

    insertUtil(child, word.substr(1));
  }

  void insert(string word)
  {
    insertUtil(root, word);
  }

  bool searchUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      return root->isTerminal;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->child[index] != NULL)
    {
      child = root->child[index];
    }
    else
    {
      return false;
    }
    return searchUtil(child, word.substr(1));
  }

  bool search(string word)
  {
    return searchUtil(root, word);
  }

  bool isEmpty(TrieNode *root)
  {
    for (int i = 0; i < 26; i++)
      if (root->child[i])
        return false;
    return true;
  }

  TrieNode *removeUtil(TrieNode *root, string word)
  {
    if (!root)
    {
      return NULL;
    }

    if (word.length() == 0)
    {
      if (root->isTerminal)
      {
        root->isTerminal = false;
      }

      if (isEmpty(root))
      {
        delete (root);
        root = nullptr;
      }
      return root;
    }

    int index = word[0] - 'A';
    root->child[index] = removeUtil(root->child[index], word.substr(1));

    if (isEmpty(root) && root->isTerminal == false)
    {
      delete (root);
      root = nullptr;
    }

    return root;
  }

  void remove(string word)
  {
    removeUtil(root, word);
  }
};

int main()
{
  Trie *t = new Trie();
  t->insert("ARM");
  t->insert("DO");
  t->insert("TIMER");
  t->insert("TIMELINE");
  t->remove("TIMER");
  cout << "Present or not " << t->search("TIMER") << endl;
  cout << "Present or not " << t->search("TIMELINE") << endl;

  return 0;
}