// link : https://leetcode.com/problems/find-duplicate-subtrees/
// using serealization store the values of duplicate Tree Node roots

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
    unordered_map<string , vector<TreeNode*>> m ;
    string dfs(TreeNode * root){
        if(!root) return "" ;
        string left_subtree = dfs(root->left) ;
        string right_subtree = dfs(root->right) ;
        string subtree = to_string(root->val) + "|" + left_subtree + "|" + right_subtree ;
        m[subtree].push_back(root) ;
        return subtree ;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> res ;
        dfs(root) ;
        for(auto x : m){
            if(x.second.size() > 1) res.push_back(x.second[0]) ;
        }
        return res ;
    }
};