// link : https://leetcode.com/problems/binary-tree-right-side-view/

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
    
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> toProcess ;
        toProcess.push(root) ;
        vector<int> res ;
        while(!toProcess.empty()) {
            int n = toProcess.size() ;
            for(int i = 0 ; i < n ; i++){
                TreeNode * current = toProcess.front() ;
                toProcess.pop() ;
                if(current){
                    if(i == n - 1) res.push_back(current->val) ;
                    if(current->left) toProcess.push(current->left) ;
                    if(current->right) toProcess.push(current->right) ;
                }
            }
        }
        return res ;
    }
};