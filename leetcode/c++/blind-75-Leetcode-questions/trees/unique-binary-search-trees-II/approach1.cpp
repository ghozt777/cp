// link : https://leetcode.com/problems/unique-binary-search-trees-ii/
// this is a slow approach using brute force

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
vector<TreeNode *> util(int start , int end){
    vector<TreeNode *> ans ;
    if(start > end){
        ans.push_back(NULL) ;
        return ans ;
    }
    for(int i = start ; i <= end ; i++){
        vector<TreeNode *> leftSubTrees = util(start , i - 1) ;
        vector<TreeNode *> rightSubTrees = util(i + 1 , end) ;
        for(TreeNode * x : leftSubTrees){
            for(TreeNode * y : rightSubTrees){
                TreeNode * root = new TreeNode(i) ;
                root->left = x ;
                root->right = y ;
                ans.push_back(root) ;
            }
        }
    }
    return ans ;
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode *> nothing ;
            return nothing ;
        }
        return util(1,n) ;
    }
};