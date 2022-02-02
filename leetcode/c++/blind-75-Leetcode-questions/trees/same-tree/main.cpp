// link : https://leetcode.com/problems/same-tree/

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
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if ((!p && q) || (!q && p))
            return false; // if one sub-treeis there but the other isn't clearly both the trees are not the same
        if (!p && !q)
            return true; // only when they reach the leaf node together they are the same
        if (p->val != q->val)
            return false;                                                      // if the values aren't the same clearly they are not the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // and check for both the left and the right subtress for both the trees
    }
};
