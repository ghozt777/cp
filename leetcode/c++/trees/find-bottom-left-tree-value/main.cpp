// link : https://leetcode.com/problems/find-bottom-left-tree-value/

// Approach : use bfs and store the first element of every level at the very last level the first element of that level is the bottom left element

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> toProcess; 
        toProcess.push(root) ;
        int res = 0 ;
        while(!toProcess.empty()){
            if(toProcess.front()){
                res = toProcess.front()->val ;
            }
            int n = toProcess.size() ;
            for(int i = 0 ; i < n ; i++){
                TreeNode * curr = toProcess.front() ;
                toProcess.pop() ;
                if(curr->left) toProcess.push(curr->left) ;
                if(curr->right) toProcess.push(curr->right) ;
            }
        }
        return res ;
    }
};