// link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    map<int,vector<pair<int,int>>> m;
    void dfs(TreeNode*root,int r=0,int c=0){
        if(!root) return ;
        m[c].push_back({r,root->val});
        dfs(root->left,r+1,c-1);
        dfs(root->right,r+1,c+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        m.clear();
        dfs(root);
        vector<vector<int>> res;
        vector<int> idx;
        for(auto &x:m)idx.push_back(x.first);
        sort(idx.begin(),idx.end());
        for(int i:idx){
            auto &y=m[i];
            sort(y.begin(),y.end());
            vector<int> r;
            for(auto &z:y)r.push_back(z.second);
            res.push_back(r);
        }
        return res;
    }
};