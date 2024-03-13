// Rabin Karp
// https://www.codingninjas.com/studio/problems/stringmatch-rabincarp_1115738?
vector<int> stringMatch(string text, string pat)
{
  int p = pat.size();
  int t = text.size();
  vector<int> ans;

  int base = 26;
  int mod = 101;

  int th = 0;
  int ph = 0;

  int h = 1; // h = base^(p-1); //this is used to calculate the power at the end of the pat because of the reverse index
  // this assure that we dont have to calcultae the exact power many time
  for (int i = 0; i < p - 1; i++)
  {
    h = (h * base) % mod;
  }

  for (int i = 0; i < p; i++)
  {
    th = ((th * base) + (text[i] - 'a' + 1)) % mod;
    ph = ((ph * base) + (pat[i] - 'a' + 1)) % mod;
  }

  int i = 0;
  for (i; i < t - p; i++)
  {
    if (th == ph)
    {
      bool match = true;

      for (int j = 0; j < p; j++)
      {
        if (text[i + j] != pat[j])
        {
          match = false;
          break;
        }
      }
      if (match)
      {
        ans.push_back(i + 1);
      }
    }
    else
    {
      th = (th + mod - ((text[i] - 'a' + 1) * h) % mod) % mod; //+mod is avoid being it in negative
      th = ((th * base) + (text[i + p] - 'a' + 1)) % mod;
    }
  }

  if (th == ph)
  {
    bool match = true;

    for (int j = 0; j < p; j++)
    {
      if (text[i + j] != pat[j])
      {
        match = false;
        break;
      }
    }
    if (match)
    {
      ans.push_back(i + 1);
    }
  }

  return ans;
  // Write your code here.
}

int firstOccurence(string &text, string &pat)
{
  // Write your code here.
  int i = 0, j = 0;
  while (i < text.size())
  {
    if (text[i] == pat[0])
    {
      j = i + 1;
      int k = 1;
      while (k < pat.size())
      {
        if (text[j] == pat[k])
        {
          j++;
          k++;
        }
        else
          break;
      }

      if (k == pat.size())
        return i;
    }
    i++;
  }

  return -1;
}