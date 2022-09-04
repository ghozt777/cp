// link: https://leetcode.com/problems/delete-leaves-with-a-given-value/

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return root;
        bool isLeaf=(!root->left&&!root->right);
        if(isLeaf){
            if(root->val==target) return NULL;
            else return root;
        }
        TreeNode*l=removeLeafNodes(root->left,target);
        TreeNode*r=removeLeafNodes(root->right,target);
        root->left=l;
        root->right=r;
        if(l || r) return root;
        else{
            if(root->val==target) return NULL;
            else return root;
        }
    }
};