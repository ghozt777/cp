// link : https://leetcode.com/problems/convert-bst-to-greater-tree/



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
    
int replace(TreeNode *root,int sum){
    if(root==NULL)
        return sum;
    
     sum=replace(root->right,sum); // max is in the right subtree so get its sum and add to current node
      sum=sum +root->val;
      root->val=sum;
      sum = replace(root->left,sum); // update left subtree to be the sum of the its parent node and right siblings
    
   return  sum; // this is the total sum of the complete subtree
    
}
void replaceWithLargerNodesSum(TreeNode*root) {
    if(root==NULL)return; 
    int ans =replace(root,0);
    return ;
  }
public:
    TreeNode* convertBST(TreeNode* root) {
        replaceWithLargerNodesSum(root) ;
        return root ;
    }
};