// link : https://leetcode.com/problems/validate-binary-search-tree/

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
    bool util(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        if (!root)
            return true;
        if (min && root->val <= min->val)
            return false;
        if (max && root->val >= max->val)
            return false;
        return util(root->left, min, root) && util(root->right, root, max);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return util(root, NULL, NULL);
    }
};