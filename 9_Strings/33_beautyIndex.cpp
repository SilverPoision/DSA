class Solution
{
public:
  vector<int> KMP(string &text, string &pat)
  {
    int n = text.size();
    int m = pat.size();
    vector<int> lps(m, 0);
    vector<int> res;

    lps[0] = 0;

    int i = 1, len = 0;
    while (i < m)
    {
      if (pat[i] == pat[len])
      {
        lps[i] = ++len;
        i++;
      }
      else
      {
        if (len != 0)
        {
          len = lps[len - 1];
        }
        else
        {
          lps[i] = 0;
          i++;
        }
      }
    }

    i = 0;
    int j = 0;
    while (i < n)
    {
      if (text[i] == pat[j])
      {
        i++;
        j++;
      }
      if (j == m)
      {
        res.push_back(i - j);
        j = lps[j - 1];
      }
      else if (i < n && pat[j] != text[i])
      {
        if (j != 0)
        {
          j = lps[j - 1];
        }
        else
        {
          i++;
        }
      }
    }

    return res;
  }
  vector<int> beautifulIndices(string s, string a, string b, int k)
  {
    vector<int> v1 = KMP(s, a);
    vector<int> v2 = KMP(s, b);

    vector<int> res;

    for (auto i : v1)
    {
      int leftLimit = max(0, i - k);
      int rightLimit = min((int)s.size() - 1, i + k);
      auto lower = lower_bound(v2.begin(), v2.end(), leftLimit);

      if (lower != v2.end() && *lower <= rightLimit &&
          *lower >= leftLimit)
      {
        res.push_back(i);
      }
    }

    return res;
  }
};

// less optimal but works
class Solution
{
public:
  vector<int> beautifulIndices(string s, string a, string b, int k)
  {
    // Vector to store the beautiful indices
    vector<int> ans, indices_a, indices_b;

    // Lengths of strings
    int x = s.size(), y = a.size(), z = b.size();

    // Step 2: Find indices of occurrences of string 'a'
    for (int i = 0; i <= x - y; i++)
    {
      if (s.substr(i, y) == a)
      {
        indices_a.push_back(i);
      }
    }

    // Step 3: Find indices of occurrences of string 'b'
    for (int j = 0; j <= x - z; j++)
    {
      if (s.substr(j, z) == b)
      {
        indices_b.push_back(j);
      }
    }

    // Step 4: Check conditions and add beautiful indices to 'ans'
    for (int i = 0; i < indices_a.size(); i++)
    {
      for (int j = 0; j < indices_b.size(); j++)
      {
        // Check if substrings match and absolute difference <= k
        if (abs(indices_a[i] - indices_b[j]) <= k)
        {
          ans.push_back(indices_a[i]);
          break;
        }
      }
    }

    // Step 5: Sort the beautiful indices in ascending order
    sort(ans.begin(), ans.end());

    // Step 6: Return the final result
    return ans;
  }
};