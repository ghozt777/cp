// link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a1,a2,res;
        parse_tree(root1,a1);
        parse_tree(root2,a2);
        int i=0,j=0;
        while(i<a1.size()&&j<a2.size()){
            if(a1[i]<=a2[j]) res.push_back(a1[i++]);
            else res.push_back(a2[j++]);
        }
        while(i<a1.size()) res.push_back(a1[i++]);
        while(j<a2.size()) res.push_back(a2[j++]);
        
        return res;
    }
};