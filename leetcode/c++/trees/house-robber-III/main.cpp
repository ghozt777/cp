// link : https://leetcode.com/problems/house-robber-iii/
// video explaination : https://www.youtube.com/watch?v=nHR8ytpzz7c

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

/*
    in util function the first element is the sum of mony if we rob the current node(house)
    the second element represents the amount of money we would earn if we dont rob the current node(house)
*/
class Solution {
    pair<int , int> util(TreeNode * root){
        if(!root) return make_pair(0 , 0) ;
        pair<int , int> l = util(root->left) ;
        pair<int , int> r = util(root->right) ;
        int withRoot = l.second + r.second + root->val ;
        int withoutRoot = max(l.first , l.second) + max(r.first , r.second) ;
        return make_pair(withRoot , withoutRoot) ;
    }
public:
    int rob(TreeNode* root) {
        pair<int , int> res = util(root) ;
        return max(res.first , res.second) ;
    }
};