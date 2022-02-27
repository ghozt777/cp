// link : https://leetcode.com/problems/count-complete-tree-nodes/

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
public:
    int countNodes(TreeNode* root){
        if(!root) return 0 ;
        int left_level = 0 ;
        int right_level = 0 ;
        TreeNode * leftPtr = root ;
        TreeNode * rightPtr = root ;
        int ans = 0 ;
        while(leftPtr) leftPtr = leftPtr->left , ++left_level ;
        while(rightPtr) rightPtr = rightPtr->right , ++right_level ;
        if(left_level == right_level) // complete filled to the brim
            ans = pow(2 , (left_level)) - 1 ;
        else ans = 1 + countNodes(root->left) + countNodes(root->right) ;
        return ans ;
    }
};

