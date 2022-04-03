// link : https://leetcode.com/problems/path-sum-iii/

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
    unordered_map<long , int> prefixSum ; // val , count
    int res ;
    int x ;
    void util(TreeNode * root , long curr){
        if(!root) return ;
        curr += root->val ;
        if(prefixSum.find(curr - x) != prefixSum.end()) res += prefixSum[curr - x] ;
        ++prefixSum[curr] ;
        util(root->left , curr) ;
        util(root->right , curr) ;
        --prefixSum[curr] ;
    }
public:
    int pathSum(TreeNode* root, int target) {
        res = 0 ;
        x = target ;
        ++prefixSum[0] ;
        util(root , 0) ;
        return res ;    
    }
};