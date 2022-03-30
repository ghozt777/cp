// link : https://leetcode.com/problems/all-possible-full-binary-trees/

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
    unordered_map<int , vector<TreeNode*>> dp ;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.find(n) != dp.end()) return dp[n] ;
        vector<TreeNode *> res ;
        if(n % 2 == 0) return res ;
        if(n == 1) return vector<TreeNode *>(1, new TreeNode()) ;
        for(int i = 0 ; i < n ; i++){
            int left = i ;
            int right = n - 1 - left ;
            vector<TreeNode *> leftSubTrees = allPossibleFBT(left) ;
            vector<TreeNode *> rightSubTrees = allPossibleFBT(right) ;
            for(auto l : leftSubTrees){
                for(auto r : rightSubTrees){
                    TreeNode * root = new TreeNode(0 , l , r) ;
                    res.emplace_back(root) ;
                }
            }
        }
        return dp[n] = res ;
    }
};