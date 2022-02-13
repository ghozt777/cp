// link : https://leetcode.com/problems/balanced-binary-tree/
// slow apprach using BF

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
    int height(TreeNode * root){
        if(!root) return 0 ;
        return 1 + max(height(root->left) , height(root->right)) ;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true ;
        int diff = height(root->left) - height(root->right) ;
        return abs(diff) <= 1 ? isBalanced(root->left) && isBalanced(root->right) : false;
    }
};