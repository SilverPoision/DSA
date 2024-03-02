/*
230. Kth Smallest Element in a BST
Medium
9.1K
162
Companies
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.



Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
*/

// Follow Up Must do
// Hwo to track the small ele if tree chnages frequently

class Solution
{
public:
  void inOrder(TreeNode *root, vector<int> &res)
  {
    if (root == NULL)
      return;

    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
    return;
  }
  int kthSmallest(TreeNode *root, int k)
  {
    vector<int> res;
    inOrder(root, res);
    return res[k - 1];
  }
};

class Solution
{
public:
  int ans;

  int kthSmallest(TreeNode *root, int k)
  {
    inorder(root, k);
    return ans;
  }

  void inorder(TreeNode *root, int &k)
  {
    if (!root)
      return;
    inorder(root->left, k);
    if (--k == 0)
    {
      ans = root->val;
      return;
    }
    inorder(root->right, k);
  }
};

class Solution
{
public:
  int kthSmallest(TreeNode *root, int k)
  {
    int cnt = k;
    int ans;
    TreeNode *curr = root;
    while (curr)
    {
      if (curr->left == NULL)
      {
        cnt--;
        if (cnt == 0)
          ans = curr->val;
        curr = curr->right;
      }
      else
      {
        TreeNode *prev = curr->left;
        while (prev->right && prev->right != curr)
        {
          prev = prev->right;
        }
        if (prev->right == NULL)
        {
          prev->right = curr;
          curr = curr->left;
        }
        else
        {
          prev->right = NULL;
          cnt--;
          if (cnt == 0)
            ans = curr->val;
          curr = curr->right;
        }
      }
    }
    return ans;
  }
};