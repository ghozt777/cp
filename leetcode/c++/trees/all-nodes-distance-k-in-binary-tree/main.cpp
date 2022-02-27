// link : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode * , TreeNode *> rel ;
        unordered_set<TreeNode *> visited ;
        queue<TreeNode *> toProcess ;
        toProcess.push(root) ;
        while(!toProcess.empty()){
            TreeNode * current = toProcess.front() ;
            toProcess.pop() ;
            if(current->left){
                rel[current->left] = current ;
                toProcess.push(current->left) ;
            }
            if(current->right){
                rel[current->right] = current ;
                toProcess.push(current->right) ;
            }
        }
        toProcess.push(target) ;
        visited.insert(target) ;
        int count = 0 ;
        while(!toProcess.empty()){
            if(count++ == k) break ;
            int n = toProcess.size() ;
            for(int i = 0 ; i < n ; i++){
                TreeNode * current = toProcess.front() ;
                toProcess.pop() ;
                TreeNode * top = rel[current] ;
                TreeNode * left = current->left ;
                TreeNode * right = current->right ;
                if(left && visited.find(left) == visited.end()){
                    toProcess.push(left) ;
                    visited.insert(left) ;
                }
                if(right && visited.find(right) == visited.end()){
                    toProcess.push(right) ;
                    visited.insert(right) ;
                }
                if(top && visited.find(top) == visited.end()){
                    toProcess.push(top) ;
                    visited.insert(top) ;
                }
            }
        }
        vector<int> res ;
        while(!toProcess.empty()){
            res.push_back(toProcess.front()->val) ;
            toProcess.pop() ;
        }
        return res ;
    }
};