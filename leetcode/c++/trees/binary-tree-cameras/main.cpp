// link : https://leetcode.com/problems/binary-tree-cameras/

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

    States: 
    0: Camera is alrady there
    1: Covered by some other camera
    2: Requires a Camera

*/

int res ;

int dfs(TreeNode*root){
    if(!root) return 1 ;
    int left=dfs(root->left);
    int right=dfs(root->right);
    if(left==2||right==2){
        ++res;
        return 0;
    }
    if(left==1&&right==1){ 
        return 2;
    }
    if(left==0||right==0){
        return 1;
    }
    return INT_MAX;
}

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        res=0;
        int r=dfs(root);
        return r==0||r==1 ? res:res+1;
    }
};