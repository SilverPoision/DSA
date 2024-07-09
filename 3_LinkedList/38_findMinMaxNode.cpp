class Solution
{
public:
  // https : // leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05
  vector<int> nodesBetweenCriticalPoints(ListNode *head)
  {
    int node = 1;
    int prev = head->val;
    head = head->next;

    vector<int> s;

    while (head->next)
    {
      if (prev > head->val && head->next->val > head->val || prev < head->val && head->next->val < head->val)
      {
        s.push_back(node);
      }
      node++;
      prev = head->val;
      head = head->next;
    }

    if (s.size() < 2)
      return {-1, -1};

    int mini = 1e9;

    for (int i = 0; i < s.size() - 1; i++)
    {
      mini = min(mini, s[i + 1] - s[i]);
    }

    return {mini, s.back() - s[0]};
  }
};