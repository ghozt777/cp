// link : https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode * dfs(vector<int> & nums , int start , int end){
        if(start > end) return NULL ;
        int maxIndex = start ;
        int max = nums[start] ;
        for(int i = start + 1 ; i <= end ; i++){
            if(nums[i] > max){
                max = nums[i] ;
                maxIndex = i ;
            }
        }
        TreeNode * root = new TreeNode(nums[maxIndex]) ;
        root->left = dfs(nums , start , maxIndex - 1) ;
        root->right = dfs(nums , maxIndex + 1 , end) ;
        return root ;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL ;
        return dfs(nums , 0 , nums.size() - 1) ;
    }
};