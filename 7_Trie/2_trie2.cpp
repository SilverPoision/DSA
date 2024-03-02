#include <bits/stdc++.h>
class Node
{
public:
  char data;
  Node *child[26];
  int ew = 0; // ends with
  int cp = 0; // count prefix

  Node(char data)
  {
    this->data = data;
    for (int i = 0; i < 26; i++)
    {
      child[i] = nullptr;
    }
  }
};

class Trie
{

public:
  Node *root;

  Trie()
  {
    // Write your code here.
    root = new Node('\0');
  }

  void insertUtil(string word, Node *root)
  {
    // Write your code here.
    if (word.length() == 0)
    {
      root->ew++;
      return;
    }

    int ind = word[0] - 'a';
    Node *child;

    if (root->child[ind] != NULL)
    {
      child = root->child[ind];
    }
    else
    {
      child = new Node(word[0]);
      root->child[ind] = child;
    }
    child->cp++;

    insertUtil(word.substr(1), child);
  }

  void insert(string &word)
  {
    insertUtil(word, root);
  }

  int countWordsEqualToUtil(string word, Node *root)
  {
    // Write your code here.
    if (word.length() == 0)
    {
      return root->ew;
    }

    int ind = word[0] - 'a';

    if (root->child[ind] != NULL)
    {
      return countWordsEqualToUtil(word.substr(1), root->child[ind]);
    }
    else
    {
      return 0;
    }
  }

  int countWordsEqualTo(string &word)
  {
    return countWordsEqualToUtil(word, root);
  }

  int countWordsStartingWithUtil(string word, Node *root)
  {
    if (word.length() == 0)
    {
      return root->cp;
    }

    int ind = word[0] - 'a';

    if (root->child[ind] != NULL)
    {
      return countWordsStartingWithUtil(word.substr(1), root->child[ind]);
    }
    else
    {
      return 0;
    }
  }

  int countWordsStartingWith(string &word)
  {
    // Write your code here.
    return countWordsStartingWithUtil(word, root);
  }

  void eraseUtil(string word, Node *root)
  {
    if (word.length() == 0)
    {
      if (root->ew > 0)
      {
        root->ew--;
      }
      return;
    }

    int ind = word[0] - 'a';
    if (root->child[ind] != NULL && root->child[ind]->cp > 0)
    {
      root->child[ind]->cp--;
      eraseUtil(word.substr(1), root->child[ind]);
    }
  }

  void erase(string &word)
  {
    // Write your code here.
    eraseUtil(word, root);
  }
};
