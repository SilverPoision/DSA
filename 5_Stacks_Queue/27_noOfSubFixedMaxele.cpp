#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;

class Solution
{
public:
  // https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/
  typedef tree<int, null_type, less<int>, rb_tree_tag,
               tree_order_statistics_node_update>
      ordered_set;
  long long numberOfSubarrays(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> ngl(n);
    unordered_map<int, ordered_set> hash;
    long long ans = 0;

    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
      int curr = nums[i];
      while (st.size() > 1 && curr >= nums[st.top()])
      {
        st.pop();
      }
      ngl[i] = st.top();
      st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
      int cul = ngl[i];
      int lb = hash[nums[i]].size() - hash[nums[i]].order_of_key(cul);
      ans += lb + 1;
      hash[nums[i]].insert(i);
    }

    return ans;
  }
};

////
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  long long numberOfSubarrays(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> nge(n, n);
    stack<int> stack;

    // Finding the Next Greater Element (NGE) to the right for each element
    for (int i = n - 1; i >= 0; i--)
    {
      while (!stack.empty() && nums[i] >= nums[stack.top()])
        stack.pop();
      if (!stack.empty())
        nge[i] = stack.top();
      stack.push(i);
    }

    // Counting the number of subarrays with odd numbers
    long long ans = 0;
    map<int, vector<int>> g;

    for (int i = 0; i < n; i++)
      g[nums[i]].push_back(i);

    for (int i = 0; i < n; i++)
    {
      int L = i, R = nge[i] - 1;
      int x = lower_bound(g[nums[i]].begin(), g[nums[i]].end(), L) - g[nums[i]].begin();
      int y = upper_bound(g[nums[i]].begin(), g[nums[i]].end(), R) - g[nums[i]].begin();
      ans += y - x;
    }

    return ans;
  }
};