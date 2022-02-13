// link : https://leetcode.com/problems/subtree-of-another-tree/


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
  bool check(TreeNode * t1 , TreeNode * t2){
    if((t1 && !t2 )|| (t2 && !t1)) return false ;
    if(!t1 && !t2) return true ;
    if(t1->val != t2->val) return false ;
    return check(t1->left , t2->left) && check(t1->right , t2->right) ;
  }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return root == subRoot ;
        return check(root , subRoot) || check(root->left , subRoot) || check(root->right , subRoot) || isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);
    }
};