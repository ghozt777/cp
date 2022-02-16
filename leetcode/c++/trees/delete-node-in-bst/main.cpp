// link : https://leetcode.com/problems/delete-node-in-a-bst/

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

    int getMin(TreeNode *curr)
    {
        if (!curr)
            return INT_MAX;
        return min(curr->val, min(getMin(curr->left), getMin(curr->right)));
    }

    TreeNode *deleteUtil(TreeNode *curr, int data)
    {
        if (!curr)
            return NULL;
        if (curr->val > data)
            curr->left = deleteUtil(curr->left, data);
        else if (curr->val < data)
            curr->right = deleteUtil(curr->right, data);
        else
        {
            if (!curr->left)
                return curr->right;
            else if (!curr->right)
                return curr->left;
            else
            {
                int _min = getMin(curr->right);
                curr->val = _min;
                curr->right = deleteUtil(curr->right, _min);
                return curr;
            }
        }
        return curr;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return deleteUtil(root, key);
    }
};