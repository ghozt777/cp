// link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        if(!root) return ;
        stack<TreeNode *> s ;
        s.push(root) ;
        while(!s.empty()){
            TreeNode * current = s.top() ;
            s.pop() ;
            if(current->right) s.push(current->right) ;
            if(current->left) s.push(current->left) ; // since we connect left node to root first we are pushing it after right so that is stays at the top
            if(!s.empty()) current->right = s.top() ; // avoid edge case when its the very last element in the stack
            current->left = NULL ;
        }
        return  ;
    }
};