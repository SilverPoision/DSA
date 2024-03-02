class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int n = s.size();

    int left = 0, right = 0, ans = 0, freq = 0;

    map<char, int> hash;

    while (left < n && right < n)
    {
      hash[s[right]]++;
      freq = max(freq, hash[s[right]]);

      if (right - left + 1 - freq > k)
      {
        // see neetcode video for explanation of why we are not finding the new maxFreq ele. at 14:00
        hash[s[left]]--;
        left++;
      }

      ans = max(ans, right - left + 1);
      right++;
    }

    return ans;
  }
};