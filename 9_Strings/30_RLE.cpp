class Solution
{
public:
  // https://leetcode.com/problems/string-compression/
  int compress(vector<char> &chars)
  {
    string str = "";
    int n = chars.size();
    char curr = chars[0];
    int occu = 1;
    int k = 0;

    for (int i = 1; i < n; i++)
    {
      if (chars[i] == curr)
      {
        occu++;
      }
      else
      {
        if (occu == 1)
        {
          chars[k++] = curr;
        }
        else
        {
          string str = curr + to_string(occu);
          for (int j = 0; j < str.size(); j++)
          {
            chars[k++] = str[j];
          }
        }
        curr = chars[i];
        occu = 1;
      }
    }

    if (occu == 1)
    {
      chars[k++] = curr;
    }
    else
    {
      string str = curr + to_string(occu);
      for (int j = 0; j < str.size(); j++)
      {
        chars[k++] = str[j];
      }
    }

    return k;
  }
};