// link : https://leetcode.com/problems/binary-tree-tilt/

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
    int res ;
    int dfs(TreeNode * root){
        if(!root) return 0 ;
        int a = dfs(root->left) ;
        int b = dfs(root->right) ;
        res += abs(a - b) ;
        return a + b + root->val ;
    }
public:
    int findTilt(TreeNode* root) {
        res = 0 ;
        dfs(root) ;
        return res ;
    }
};