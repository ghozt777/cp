// link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

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
    int res=0;
    pair<int,int> dfs(TreeNode *root){
        if(!root) return {0,0};
        int div=1;
        int sum=root->val;
        if(root->left){
            auto res=dfs(root->left);
            sum+=res.first;
            div+=res.second;
        }
        if(root->right){
            auto res=dfs(root->right);
            sum+=res.first;
            div+=res.second;
        }
        if(sum/div==root->val) ++res;
        return {sum,div};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        res=0;
        dfs(root);
        return res;
    }
};