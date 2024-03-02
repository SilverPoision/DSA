class Solution
{
public:
  // best one
  // https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    int n = arr.size();
    unordered_map<int, int> hash;
    for (auto it : arr)
    {
      hash[it]++;
    }

    vector<int> freq(n + 1, 0);

    for (auto it : hash)
    {
      freq[it.second]++;
    }

    int uniqueTypes = hash.size();

    for (int i = 1; i <= n; i++)
    {
      int numberofTypesIcanDel = min(k / i, freq[i]);
      uniqueTypes -= numberofTypesIcanDel;

      k -= numberofTypesIcanDel * i;

      if (k <= i)
        return uniqueTypes; // if k == i we cannot move further because i
                            // is done and we have to go to i+1 ele and that ele will already
                            // be greater than i and k so we cannot remove it even 1 type
    }

    return 0;
  }
};

class Solution
{
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> hash;
    for (auto it : arr)
    {
      hash[it]++;
    }

    for (auto it : hash)
    {
      pq.push(it.second);
    }

    while (k)
    {
      int top = pq.top();
      pq.pop();
      if (top <= k)
        k = k - top;
      else
      {
        pq.push(top);
        break;
      }
    }

    return pq.size();
  }
};

class Solution
{
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    sort(arr.begin(), arr.end());
    vector<int> V = {1};
    for (int i = 1; i < arr.size(); i++)
    {
      if (arr[i] == arr[i - 1])
      {
        V.back()++;
      }
      else
      {
        V.push_back(1);
      }
    }
    sort(V.begin(), V.end());
    int ans = V.size();
    for (int i = 0; i < V.size(); i++)
    {
      if (V[i] <= k)
      {
        ans--;
        k -= V[i];
      }
      else
      {
        break;
      }
    }
    return ans;
  }
};