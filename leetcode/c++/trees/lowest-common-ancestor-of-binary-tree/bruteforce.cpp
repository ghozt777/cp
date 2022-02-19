// link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// NOT THE BEST TIME COMPLEXITY

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool contains(TreeNode * root , TreeNode * target){
        if(!root) return false ;
        if(root == target) return true ;
        return contains(root->left , target) || contains(root->right , target) ;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL ;
        bool lAns = contains(root->left , p) && contains(root->left , q) ;
        bool rAns = contains(root->right , p) && contains(root->right , q) ;
        if(lAns) return lowestCommonAncestor(root->left , p , q) ;
        else if(rAns) return lowestCommonAncestor(root->right , p , q) ;
        else return root ;
    }
};