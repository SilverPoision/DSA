class Solution
{
public:
  string smallestSubsequence(string s, int k, char letter, int repetition)
  {
    int n = s.size();
    int left = count(s.begin(), s.end(), letter);
    string st;

    for (int i = 0; i < n; i++)
    {
      char currentChar = s[i];

      // Pop characters from the result string 'st' if they are greater than the current character,
      // and the remaining characters in 'st' along with those in the remaining part of 's' can make up 'k',
      // and the character is not the required 'letter' or 'repetition' limit has been reached.
      while (!st.empty() &&
             st.back() > currentChar &&
             (st.size() + n - i) > k &&
             (st.back() != letter || left > repetition))
      {
        char last = st.back();
        if (last == letter)
        {
          repetition++;
        }
        st.pop_back();
      }

      // If there is space for more characters, add the current character to 'st'.
      if (k > st.size())
      {
        if (currentChar == letter || k - (int)st.size() > repetition)
        // if all the eles before the target letter are short then this will
        // comehandy and will not let push any ele in the st unless there is
        // more space left than reps.
        {
          st += currentChar;
          if (currentChar == letter)
          {
            repetition--;
          }
        }
      }

      // Update the count of remaining 'letter' characters in 's'.
      if (currentChar == letter)
      {
        left--;
      }
    }

    return st;
  }
};

class Solution
{
public:
  string ans = "";
  void f(int i, string s, int k, char letter, int rep, string out)
  {
    if (i >= s.size() || k == 0)
    {
      if (rep <= 0 && k == 0)
      {
        if (ans == "")
        {
          ans = out;
        }
        else
        {
          if (ans > out)
            ans = out;
        }
      }
      return;
    }

    f(i + 1, s, k - 1, letter, (s[i] == letter ? rep - 1 : rep), out + s[i]);
    f(i + 1, s, k, letter, rep, out);
  }
  string smallestSubsequence(string s, int k, char letter, int rep)
  {
    int n = s.size();
    f(0, s, k, letter, rep, "");
    return ans;
  }
};