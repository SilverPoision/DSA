// memo
class Solution
{
public:
  int ans = 0;
  int f(int i, int j, vector<int> &nums1, vector<int> &nums2, int n, int m, vector<vector<int>> &dp)
  {
    if (i >= n || j >= m)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    f(i + 1, j, nums1, nums2, n, m, dp);
    f(i, j + 1, nums1, nums2, n, m, dp);

    if (nums1[i] == nums2[j])
    {
      dp[i][j] = 1 + f(i + 1, j + 1, nums1, nums2, n, m, dp);
    }
    else
    {
      dp[i][j] = 0; // for substring and remove this for subsequence
    }

    ans = max(ans, dp[i][j]);

    return dp[i][j];
  }
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    f(0, 0, nums1, nums2, n, m, dp);
    return ans;
  }
};

// tab
class Solution
{
public:
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        if (nums1[i] == nums2[j])
        {
          dp[i][j] = 1 + dp[i + 1][j + 1];
          ans = max(ans, dp[i][j]);
        }
        else
        {
          dp[i][j] = 0;
        }
      }
    }

    return ans;
  }
};

// so
class Solution
{
public:
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        if (nums1[i] == nums2[j])
        {
          curr[j] = 1 + prev[j + 1];
          ans = max(ans, curr[j]);
        }
        else
        {
          curr[j] = 0;
        }
      }
      prev = curr;
    }

    return ans;
  }
};

// non dp
class Solution
{
public:
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums2.size();
    int m = nums1.size();
    unordered_map<int, vector<int>> hash;

    for (int i = 0; i < n; i++)
    {
      hash[nums2[i]].push_back(i);
    }

    int maxi = 0;

    for (int i = 0; i < m; i++)
    {
      if (hash.find(nums1[i]) != hash.end())
      {
        int localMaxi = 0;
        for (auto it : hash[nums1[i]])
        {
          if (maxi > n - it)
            continue;
          int s = i;
          int j = it;
          while (s < m && j < n)
          {
            if (nums1[s] == nums2[j])
            {
              localMaxi = max(localMaxi, s - i + 1);
              s++;
              j++;
            }
            else
              break;
          }
        }
        maxi = max(localMaxi, maxi);
      }
    }

    return maxi;
  }
};