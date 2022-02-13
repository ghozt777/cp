// link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}12
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int currentRootIdx = 0;
    TreeNode *util(vector<int> pre, vector<int> in, int startIdx, int endIdx)
    {
        if (startIdx > endIdx)
            return NULL;
        TreeNode *root = new TreeNode(pre[currentRootIdx++]);
        int idx = 0;
        for (int i = startIdx; i <= endIdx; i++)
        {
            if (in[i] == root->val)
            {
                idx = i;
                break;
            }
        }
        root->left = util(pre, in, startIdx, idx - 1);
        root->right = util(pre, in, idx + 1, endIdx);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return util(preorder, inorder, 0, inorder.size() - 1);
    }
};

// driver code :

void bfs(TreeNode *root)
{
    queue<TreeNode *> current;
    current.push(root);
    cout << "bfs print :" << endl;
    while (!current.empty())
    {
        int n = current.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = current.front();
            current.pop();
            cout << curr->val << " ";
            if (curr->left)
                current.push(curr->left);
            if (curr->right)
                current.push(curr->right);
        }
        cout << endl;
    }
}

int main()
{

    Solution s;
    int n;
    cin >> n;
    vector<int> inorder(n);
    vector<int> preorder(n);
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    TreeNode *root = s.buildTree(preorder, inorder);
    bfs(root);
    return 0;
}
