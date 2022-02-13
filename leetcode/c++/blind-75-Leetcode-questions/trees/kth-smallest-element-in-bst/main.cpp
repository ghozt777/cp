// link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int res = 0;

public:
    void inorder(TreeNode *root, int &k)
    {
        if (!root)
            return;
        inorder(root->left, k);
        if (k == 1)
            res = root->val;
        inorder(root->right, --k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return res;
    }
};