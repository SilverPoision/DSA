class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
  int maxSize = 0;
  int maxSum = 0;

  void solve(Node *root, int level, int sum)
  {
    if (!root)
    {
      if (level > maxSize)
      {
        maxSum = sum;
        maxSize = level;
      }
      else if (level == maxSize)
      {
        maxSum = max(maxSum, sum);
      }
      return;
    }

    solve(root->left, level + 1, root->data + sum);
    solve(root->right, level + 1, root->data + sum);
  }

  int sumOfLongRootToLeafPath(Node *root)
  {
    // code here
    solve(root, 0, 0);
    return maxSum;
  }
};