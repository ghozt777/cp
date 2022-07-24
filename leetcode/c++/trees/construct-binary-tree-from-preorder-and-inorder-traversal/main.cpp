// link:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
// ro -> l -> r
// l -> ro -> r
class Solution {
    TreeNode* solve(int start,int end,int&idx,vector<int>&inorder,vector<int>&preorder){
        if(start<0||end<start||idx>=preorder.size()) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        int pos=-1;
        for(int i=0;i<inorder.size();i++) if(inorder[i]==preorder[idx]){
            pos=i;
            break;
        }
        ++idx;
        root->left=solve(start,pos-1,idx,inorder,preorder);
        root->right=solve(pos+1,end,idx,inorder,preorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return solve(0,inorder.size()-1,idx,inorder,preorder);
    }
};