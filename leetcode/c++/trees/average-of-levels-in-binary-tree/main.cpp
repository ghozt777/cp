// lnik : https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res ;
        queue<TreeNode * > toProcess ;
        toProcess.push(root) ;
        while(!toProcess.empty()){
            int n = toProcess.size() ;
            double sum = 0.00 ;
            for(int i = 0 ; i < n ; i++){
                TreeNode * curr = toProcess.front() ;
                toProcess.pop() ;
                sum += curr->val ;
                if(curr->left) toProcess.push(curr->left) ;
                if(curr->right) toProcess.push(curr->right) ;
            }
            res.emplace_back(sum / n) ;
        }
        return res ;
    }
};