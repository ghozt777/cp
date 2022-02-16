// link : https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/

/*
    IDEA : use inorder traversal
    In BST inorder traversal is a sorted
    Check adjacent elements and comapre if they are same
    if they are update acoordingly
    If more than one elemnet have the same count that is max so far push into the vector
    else if some elements count is more than max so far clear the vector and insert that element
    for every new element we rest the count to 1
*/

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
class Solution
{
    int prev = INT_MIN;
    int curr = 0;
    int _max = 0;
    void util(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        util(root->left, ans);

        if (root->val == prev)
            ++curr;
        else
            curr = 1;
        if (curr == _max)
            ans.push_back(root->val);
        if (curr > _max)
        {
            ans.clear();
            ans.push_back(root->val);
            _max = curr;
        }
        prev = root->val;

        util(root->right, ans);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> ans;
        util(root, ans);
        return ans;
    }
};