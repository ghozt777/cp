// link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode * dfs(vector<int>& preorder,int curr , int end){
        if(curr < 0 || curr > end) return NULL ;
        TreeNode * root = new TreeNode(preorder[curr]) ;
        int p = curr ;
        while(
            (p <= end) && 
            (preorder[p] <= preorder[curr])
        ){
            ++p;
        }
        root->left = dfs(preorder,curr + 1 , p - 1);
        root->right = dfs(preorder,p , end);
        return root ;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder,0,preorder.size() - 1) ;
    }
};