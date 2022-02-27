// link : https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    vector<vector<int>> res ;
    void util(TreeNode * root , vector<int> & curr){
        if(!root) return ;
        if(!root->left && !root->right){
            curr.push_back(root->val) ;
            res.push_back(curr) ;
            curr.pop_back() ;
        }
        curr.push_back(root->val) ;
        util(root->left , curr) ;
        util(root->right , curr) ;
        curr.pop_back() ;
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> curr ;
        util(root , curr) ;
        int ans = 0 ;
        for(auto x : res){
            int curr = 0 ;
            for(int i = 0 ; i < x.size() ; i++){
                curr = curr * 10 + x[i] ;
            }
            ans += curr ;
        }
        return ans ;
    }
};

