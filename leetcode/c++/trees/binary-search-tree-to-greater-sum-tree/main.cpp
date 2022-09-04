// link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    int dfs(TreeNode* root,int to_add=0){
        if(!root) return 0;
        int to_return=root->val;
        int r=dfs(root->right,to_add);
        int l=dfs(root->left,root->val+r+to_add);
        to_return+=l+r;
        root->val+=r+to_add;
        return to_return;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};