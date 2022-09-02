// link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/


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
    const int INF=INT_MAX;
    int res;
    pair<int,int> dfs(TreeNode*root){
        if(!root) return {INF,INT_MIN};
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        if(l.first!=INF)res=max({res,abs(root->val-l.first),abs(root->val-l.second)});
        if(r.first!=INF)res=max({res,abs(root->val-r.first),abs(root->val-r.second)});
        return {min({root->val,l.first,r.first}),max({root->val,l.second,r.second})};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        this->res=0;
        dfs(root);
        return this->res;
    }
};