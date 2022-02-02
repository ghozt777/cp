// link : https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int ans = INT_MIN; // global answer variable
    int util(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_max = max(0, util(root->left));            // check to avoid path with negative sum
        int right_max = max(0, util(root->right));          // check to avoid path with negative sum
        ans = max(ans, (root->val + left_max + right_max)); // update answer accordingly
        return max(left_max, right_max) + root->val;        // choose between left and right subtree and add current val
        //(we can't return both left and right subtree values as then it forms a closed path and we can't include the current node's parent)
    }

public:
    int maxPathSum(TreeNode *root)
    {
        util(root); // once the calculation is done return the globally maintained answer
        return ans;
    }
};