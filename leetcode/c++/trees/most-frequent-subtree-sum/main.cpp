// link : https://leetcode.com/problems/most-frequent-subtree-sum/

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
    unordered_map<int , int> m ;
    int dfs(TreeNode * root){
        if(!root) return 0 ;
        if(!root->left && !root->right){
            ++m[root->val] ;
            return root->val ;
        }
        if(root->left && root->right){
            int a = dfs(root->left) ;
            int b = dfs(root->right) ;
            ++m[a + b + root->val] ;
            return a + b + root->val ;
        }
        else if(root->left){
            int a = dfs(root->left) ;
            ++m[a + root->val] ;
            return a + root->val ;
        }
        else{
            int b = dfs(root->right) ;
            ++m[b + root->val] ;
            return b + root->val ;
        }
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root) ;
        vector<int> res ;
        int maxCount = 0 ;
        for(auto x : m){
            if(x.second > maxCount){
                res.clear() ;
                maxCount = x.second ;
                res.emplace_back(x.first) ;
            }
            else if(x.second == maxCount) 
                res.emplace_back(x.first) ;
        }
        return res ;
    }
};