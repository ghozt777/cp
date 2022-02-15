// link : https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
    vector<int> inorder ;
    int curr ;
    void genInorder(TreeNode * root){
        if(!root) return ;
        genInorder(root->left) ;
        inorder.push_back(root->val) ;
        genInorder(root->right) ;
    }
public:
    BSTIterator(TreeNode* root) {
        genInorder(root) ;
        curr = 0 ;
    }
    
    int next() {
        return inorder[curr++] ;
    }
    
    bool hasNext() {
        return curr != inorder.size() ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */