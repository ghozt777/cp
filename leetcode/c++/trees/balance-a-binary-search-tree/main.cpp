// link: https://leetcode.com/problems/balance-a-binary-search-tree/
 
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
    void parse_tree(TreeNode*root,vector<int>&curr){
        if(!root) return ;
        parse_tree(root->left,curr);
        curr.push_back(root->val);
        parse_tree(root->right,curr);
    }
    TreeNode* gen_BST(vector<int>&arr,int start,int end){
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode *root=new TreeNode(arr[mid]);
        root->left=gen_BST(arr,start,mid-1);
        root->right=gen_BST(arr,mid+1,end);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        parse_tree(root,arr);
        return gen_BST(arr,0,arr.size()-1);
    }
};