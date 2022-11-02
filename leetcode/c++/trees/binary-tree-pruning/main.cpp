// link: https://leetcode.com/problems/binary-tree-pruning/

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
class Solution {
    bool has_one(TreeNode*root){
        if(!root) return false;
        bool left_has_one=has_one(root->left);
        bool right_has_one=has_one(root->right);
        bool has_one = left_has_one || right_has_one || root->val==1;
        if(!left_has_one) root->left=NULL;
        if(!right_has_one) root->right=NULL;
        return has_one;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool check_if_root_has_one=has_one(root);
        return check_if_root_has_one?root:NULL;
    }
};