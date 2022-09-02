// link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    void getTwoLevelDown(TreeNode *root,int curr=0){
        if(!root) return;
        if(curr==2){
            res+=root->val;
            return;
        }
        getTwoLevelDown(root->left,curr+1);
        getTwoLevelDown(root->right,curr+1);
        return ;
    }
    void dfs(TreeNode*root){
        if(!root) return ;
        if(root->val%2==0) getTwoLevelDown(root);
        dfs(root->left);
        dfs(root->right);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        res=0;
        dfs(root);
        return res;
    }
};