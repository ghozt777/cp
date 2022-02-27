// idea : use backtracking
// link : https://leetcode.com/problems/path-sum-ii/

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
    void util(TreeNode * root , int target , vector<int> & curr){
        if(!root) return ;
        if(!root->left && !root->right && (target - root->val == 0)){
            curr.push_back(root->val) ;
            res.push_back(curr) ;
            curr.pop_back();
        }
        curr.push_back(root->val) ;
        util(root->left , target - root->val , curr) ;
        util(root->right , target - root->val , curr) ;
        curr.pop_back() ;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> buff ;
        util(root , targetSum , buff) ;
        return res ;
    }
};