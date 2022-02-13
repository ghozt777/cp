// link : https://leetcode.com/problems/minimum-absolute-difference-in-bst/

// uses inorder traversal and stores the prev nodes sices its a BST its gotta be between parent and child nodes

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
    int _min = INT_MAX ;
    TreeNode * prev = NULL ;
    void dfs(TreeNode * root){
        if(!root) return ;
        dfs(root->left) ;
        if(prev) _min = min(_min , abs(prev->val - root->val)) ;
        prev = root ;
        dfs(root->right) ;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root) ;
        return _min ;
    }
};