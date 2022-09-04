// link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int res;
    void dfs(TreeNode*root,int check){
        if(!root) return;
        if(root->val>=check) ++res; 
        dfs(root->left,max(check,root->val));
        dfs(root->right,max(check,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        res=0;
        dfs(root,INT_MIN);
        return res;
    }
};