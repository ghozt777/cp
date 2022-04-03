// link : https://leetcode.com/problems/add-one-row-to-tree/

// algo : use bfs reach second last level from depth and add the nodes 

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root ;
        if(depth == 1) return new TreeNode(val , root , NULL) ;
        int curr = 1 ;
        queue<TreeNode *> toProcess ;
        toProcess.push(root) ;
        while(!toProcess.empty() && curr++ != depth - 1){
            int n = toProcess.size() ;
            for(int i = 0 ; i < n ; i++){
                TreeNode * curr = toProcess.front() ;
                toProcess.pop() ;
                if(curr->left) toProcess.push(curr->left) ;
                if(curr->right) toProcess.push(curr->right) ;
            }
        }
        while(!toProcess.empty()){
            TreeNode * curr = toProcess.front() ;
            toProcess.pop() ;
            if(curr->left){
                TreeNode * temp = curr->left ;
                curr->left = new TreeNode(val , temp , NULL) ;
            }
            else curr->left = new TreeNode(val) ;
            if(curr->right){
                TreeNode * temp = curr->right ;
                curr->right = new TreeNode(val , NULL , temp) ;
            }
            else curr->right = new TreeNode(val) ;
        }
        return root ;
    }
};