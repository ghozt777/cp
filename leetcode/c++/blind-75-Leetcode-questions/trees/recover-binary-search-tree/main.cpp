// link : https://leetcode.com/problems/recover-binary-search-tree/ 

/*
    IDEA : use inorder traversal in an ideal situation for a BST -> inorder traversal is ascending 
           hence to find the swaped nodes find the elements at wrong position and then swap their values
*/ 

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
    // inorder traversal of a BST results in a ascending array
    // we just need to find the two misplaced elements and swap their values 
    TreeNode * prev = NULL ;
    TreeNode * firstElement = NULL ;
    TreeNode * secondElement = NULL ;
    
    void inorder(TreeNode * root){
        if(!root) return ;
        
        inorder(root->left) ;
        
        if(!firstElement && prev && prev->val >= root->val) firstElement = prev ; // previous element was misplaced as it is larger and belongs in the end of the list
        if(firstElement && prev && prev->val >= root->val) secondElement = root ; // current element is misplaced as its smaller and belongs in the front of the list
        prev = root ;
        
        inorder(root->right) ;
        
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root) ;
        int temp = firstElement->val ;
        firstElement->val = secondElement->val ;
        secondElement->val = temp ;
        return ;
    }
};