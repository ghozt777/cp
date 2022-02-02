// link : https://leetcode.com/problems/binary-tree-level-order-traversal/
// also known as BREATH FIRST SEARCH (BFS)
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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> toProcess;
        toProcess.push(root);
        while (!toProcess.empty())
        {
            int n = toProcess.size();
            vector<int> currentLevel;
            for (int i = 0; i < n; i++)
            {
                TreeNode *current = toProcess.front();
                toProcess.pop();
                currentLevel.push_back(current->val);
                if (current->left)
                    toProcess.push(current->left);
                if (current->right)
                    toProcess.push(current->right);
            }
            ans.push_back(currentLevel);
        }
        return ans;
    }
};