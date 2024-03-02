class Solution
{
public:
  int f(int i, string &s, unordered_map<string, int> &hash, vector<int> &dp)
  {
    if (i == s.size())
      return 0;

    if (dp[i] != -1)
      return dp[i];

    int res = 1 + f(i + 1, s, hash, dp);

    string temp = "";
    for (int k = i; k < s.size(); k++)
    {
      temp += s[k];
      if (hash.find(temp) != hash.end())
      {
        res = min(res, f(k + 1, s, hash, dp));
      }
    }

    return dp[i] = res;
  }
  int minExtraChar(string s, vector<string> &d)
  {
    int n = s.size();
    unordered_map<string, int> hash;
    for (auto it : d)
      hash[it]++;
    vector<int> dp(n, -1);
    return f(0, s, hash, dp);
  }
};

// tab
class Solution
{
public:
  int minExtraChar(string s, vector<string> &d)
  {
    int n = s.size();
    unordered_map<string, int> hash;
    for (auto it : d)
      hash[it]++;
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      int res = 1 + dp[i + 1];

      string temp = "";
      for (int k = i; k < s.size(); k++)
      {
        temp += s[k];
        if (hash.find(temp) != hash.end())
        {
          res = min(res, dp[k + 1]);
        }
      }

      dp[i] = res;
    }

    return dp[0];
  }
};

// More optimized with tie but not required
struct TrieNode
{
  bool isEnd;
  TrieNode *links[26];
  TrieNode()
  {
    isEnd = 0;
    fill(links, links + 26, (TrieNode *)NULL);
  }
};
class Trie
{
public:
  TrieNode *root;
  Trie()
  {
    root = new TrieNode();
  }
  ~Trie()
  {              // destructor
    delete root; // avoid memory leaks
  }

  void insert(string &word)
  {
    TrieNode *Node = root;
    for (char c : word)
    {
      int i = c - 'a';
      if (Node->links[i] == NULL)
        Node->links[i] = new TrieNode();
      Node = Node->links[i];
    }
    Node->isEnd = 1;
  }
  void insert(vector<string> &dictionary)
  {
    for (auto &word : dictionary)
      insert(word);
  }
};

class Solution
{
public:
  int minExtraChar(string s, vector<string> &dictionary)
  {
    Trie trie;
    trie.insert(dictionary); // Insert all words in trie

    int n = s.size();
    vector<int> dp(n + 1, 0); // dp[i]=the minimum extra characters needed for s[i:end]
    for (int i = n - 1; i >= 0; i--)
    {
      dp[i] = dp[i + 1] + 1;
      TrieNode *node = trie.root;
      for (int j = i; j < n; j++)
      {
        if (node->links[s[j] - 'a'] == NULL)
          break; // next i--
        node = node->links[s[j] - 'a'];
        if (node->isEnd) // A word in dictionary is found
          dp[i] = min(dp[i], dp[j + 1]);
      }
    }
    return dp[0];
  }
};