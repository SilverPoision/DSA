class Solution
{
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> st(wordList.begin(), wordList.end());

    // Creating a queue ds which stores the words in a sequence which is
    // required to reach the targetWord after successive transformations.
    queue<vector<string>> q;

    // BFS traversal with pushing the new formed sequence in queue
    // when after a transformation, a word is found in wordList.

    q.push({beginWord});

    // A vector defined to store the words being currently used
    // on a level during BFS.
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;

    // A vector to store the resultant transformation sequence.
    vector<vector<string>> ans;
    while (!q.empty())
    {
      vector<string> vec = q.front();
      q.pop();

      // Now, erase all words that have been
      // used in the previous levels to transform
      if (vec.size() > level)
      {
        level++;
        for (auto it : usedOnLevel)
        {
          st.erase(it);
        }
      }

      string word = vec.back();

      // store the answers if the end word matches with targetWord.
      if (word == endWord)
      {
        // the first sequence where we reached end
        if (ans.size() == 0)
        {
          ans.push_back(vec);
        }
        else if (ans[0].size() == vec.size())
        {
          ans.push_back(vec);
        }
      }
      for (int i = 0; i < word.size(); i++)
      {
        // Now, replace each character of ‘word’ with char
        // from a-z then check if ‘word’ exists in wordList.
        char original = word[i];
        for (char c = 'a'; c <= 'z'; c++)
        {
          word[i] = c;
          if (st.count(word) > 0)
          {
            // Check if the word is present in the wordList and
            // push the word along with the new sequence in the queue.
            vec.push_back(word);
            q.push(vec);
            // mark as visited on the level
            usedOnLevel.push_back(word);
            vec.pop_back();
          }
        }
        word[i] = original;
      }
    }
    return ans;
  }
};

// Optimal cp way
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  // Create a map of type word->level to get the idea
  // on which level the word comes after the transformations.
  unordered_map<string, int> mpp;

  // A vector for storing the final answer.
  vector<vector<string>> ans;
  string b;

private:
  void dfs(string word, vector<string> &seq)
  {
    // Function for implementing backtracking using the created map
    // in reverse order to find the transformation sequence in less time.

    // Base condition :
    // If word equals beginWord, we’ve found one of the sequences
    // simply reverse the sequence and return.
    if (word == b)
    {
      reverse(seq.begin(), seq.end());
      ans.push_back(seq);

      // reverse again so that the dfs calls are not disturbed.
      reverse(seq.begin(), seq.end());
      return;
    }
    int sz = word.size();
    int steps = mpp[word];

    // Replace each character of the word with letters from a-z
    // and check whether the transformed word is present in the map
    // and at the previous level or not.
    for (int i = 0; i < sz; i++)
    {
      char original = word[i];
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        word[i] = ch;
        if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
        {
          seq.push_back(word);
          dfs(word, seq);
          // pop the current word from the back of the queue
          // to traverse other possibilities.
          seq.pop_back();
        }
      }
      word[i] = original;
    }
  }

public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    // Push all values of wordList into a set
    // to make deletion from it easier and in less time complexity.
    unordered_set<string> st(wordList.begin(), wordList.end());

    // Perform BFS traversal and push the string in the queue
    // as soon as they’re found in the wordList.
    queue<string> q;
    b = beginWord;
    q.push({beginWord});

    // beginWord initialised with level 1.
    mpp[beginWord] = 1;
    int sz = beginWord.size();
    st.erase(beginWord);
    while (!q.empty())
    {

      string word = q.front();
      int steps = mpp[word];
      q.pop();

      // Break out if the word matches the endWord
      if (word == endWord)
        break;

      // Replace each character of the word with letters from a-z
      // and check whether the transformed word is present in the
      // wordList or not, if yes then push to queue
      for (int i = 0; i < sz; i++)
      {
        char original = word[i];

        for (char ch = 'a'; ch <= 'z'; ch++)
        {

          word[i] = ch;
          if (st.count(word))
          {
            q.push(word);
            st.erase(word);

            // push the word along with its level
            // in the map data structure.
            mpp[word] = steps + 1;
          }
        }
        word[i] = original;
      }
    }

    // If we reach the endWord, we stop and move to step-2
    // that is to perform reverse dfs traversal.
    if (mpp.find(endWord) != mpp.end())
    {
      vector<string> seq;
      seq.push_back(endWord);
      dfs(endWord, seq);
    }
    return ans;
  }
};
