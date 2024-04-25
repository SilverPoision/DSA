#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  char data;
  TrieNode *child[26];
  int childCount;
  bool isTerminal;

  TrieNode(char data)
  {
    this->data = data;
    for (int i = 0; i < 26; i++)
    {
      child[i] = nullptr;
    }
    isTerminal = 0;
    childCount = 0;
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

    int index = word[0] - 'a';
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
      root->childCount++;
      root->child[index] = child;
    }

    insertUtil(child, word.substr(1));
  }

  void insert(string word)
  {
    insertUtil(root, word);
  }
};

string longestCommonPrefix(vector<string> &arr)
{
  Trie *t = new Trie();
  for (auto it : arr)
  {
    t->insert(it);
  }

  string ans = "";
  TrieNode *child = t->root;
  int i = 0;
  while (child->childCount == 1)
  {
    int index;
    if (i < arr[0].length())
    {
      ans.push_back(arr[0][i]);
      index = arr[0][i++] - 'a';
    }
    else
    {
      break;
    }

    child = child->child[index];
  }
  return ans;
}

int main()
{
  vector<string> st;
  st.push_back("coding");
  st.push_back("codezen");
  st.push_back("codingninja");
  st.push_back("coder");
  string sr = longestCommonPrefix(st);
  cout << sr;
  return 0;
}

// string longestCommonPrefix(vector<string> &arr, int n)
// {
//   string ans = "";

//   for (int i = 0; i < arr[0].length(); i++)
//   {
//     char ch = arr[0][i];
//     bool match = true;

//     for (int j = 1; j < arr.size(); j++)
//     {
//       if (arr[j].length() < i || ch != arr[j][i])
//       {
//         match = false;
//         break;
//       }
//     }
//     if (match == false)
//     {
//       break;
//     }
//     else
//     {
//       ans.push_back(ch);
//     }
//   }
//   return ans;
// }
