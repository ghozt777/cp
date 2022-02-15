// link : https://leetcode.com/problems/binary-tree-paths/ 

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
    void util(vector<string> &ans , TreeNode* root , string p){
        if(!root) return ;
        if(!root->left && !root->right && root){p.append(to_string(root->val)) ; ans.push_back(p) ; return;}
        p.append(to_string(root->val) + "->") ;
        util(ans,root->left , p) ;
        util(ans,root->right , p) ;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans ;
        util(ans , root , "") ;
        return ans ;
    }
};