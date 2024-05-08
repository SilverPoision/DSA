class Solution
{
public:
  // https://leetcode.com/problems/valid-word/
  bool isValid(string word)
  {
    int n = word.size();
    if (n < 3)
      return false;

    unordered_set<char> s = {'a', 'e', 'i', 'o', 'u',
                             'A', 'E', 'I', 'O', 'U'};

    bool vowel = false;
    bool cons = false;

    for (auto it : word)
    {
      if (isalpha(it))
      {
        if (s.count(it))
        {
          vowel |= true;
        }
        else
        {
          cons |= true;
        }
      }
      if (it == '@' || it == '#' || it == '$')
        return false;
    }

    return (vowel && cons);
  }
};