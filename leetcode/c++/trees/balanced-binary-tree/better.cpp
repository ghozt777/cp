// link : https://leetcode.com/problems/balanced-binary-tree/

// this uses O(n) time using bottoms up approach where each node is visited just once

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
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftSubTreeHeight = dfs(root->left);
        if (leftSubTreeHeight == INT_MIN)
            return INT_MIN;
        int rightSubTreeHeight = dfs(root->right);
        if (rightSubTreeHeight == INT_MIN)
            return INT_MIN;
        if (abs(leftSubTreeHeight - rightSubTreeHeight) > 1)
            return INT_MIN;
        return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return dfs(root) != INT_MIN;
    }
};
