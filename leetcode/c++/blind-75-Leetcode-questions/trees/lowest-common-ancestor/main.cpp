// link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*
    IDEA : If both the nodes p and q exist in the left subtree then search in the left subtree
           else if both the nodes exist in the right subtree search in the right subtree
           else both the nodes exist in different subtrees and the current node is the lowest common ancestor(LCA)
*/

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL ;
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left , p , q) ; // both exist in the left subtree
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right , p , q) ; // both exist in the right subtree
        else return root ; //  both exist in the different subtrees and the current node is the LCA
        return NULL ;
    }
};