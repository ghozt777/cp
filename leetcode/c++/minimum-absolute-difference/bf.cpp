// link : https://leetcode.com/problems/minimum-absolute-difference-in-bst/

// uses brute force
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
    void addNodes(vector<int> &nodes , TreeNode * root){
        if(!root) return ;
        nodes.push_back(root->val) ;
        addNodes(nodes , root->left) ;
        addNodes(nodes , root->right) ;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes ;
        addNodes(nodes, root) ; 
        int n = nodes.size() ;
        sort(nodes.begin() ,nodes.end()) ;
        int diff = INT_MAX ;
        for(int i = 1 ; i < n ; i++) diff = min(diff , (nodes[i] - nodes[i-1])) ;
        return diff ;
    }
};