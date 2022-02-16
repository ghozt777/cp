// link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


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
    TreeNode * genTree(vector<int>&in , vector<int>&post , int start , int end , int & curr){
        if(start > end) return NULL ;
        TreeNode * root = new TreeNode(post[curr--]) ;
        int i = start ;
        for(; i<=end && in[i] != root->val ; i++) ;
        root->right = genTree(in , post , i + 1 , end , curr) ;
        root->left = genTree(in , post , start , i - 1 , curr) ;
        return root ;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int curr = postorder.size() - 1 ;
        return genTree(inorder , postorder , 0 , curr , curr) ;
    }
};