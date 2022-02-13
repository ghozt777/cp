// link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// algo used : Level Order Traversal

#include <bits/stdc++.h>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string toSend = "";
        queue<TreeNode *> level;
        level.push(root);
        while (!level.empty())
        {
            TreeNode *current = level.front();
            level.pop();
            if (!current)
                toSend.append("#,");
            else
            {
                toSend.append(to_string(current->val) + ",");
                level.push(current->left);
                level.push(current->right);
            }
        }
        return toSend;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return NULL;
        stringstream s(data);
        string ch;
        getline(s, ch, ',');
        TreeNode *root = new TreeNode(stoi(ch));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            getline(s, ch, ',');
            if (ch != "#")
            {
                TreeNode *leftNode = new TreeNode(stoi(ch));
                current->left = leftNode;
                q.push(leftNode);
            }
            getline(s, ch, ',');
            if (ch != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(ch));
                current->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

void dfs(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }
}

// driver code 

int main()
{
    TreeNode *root = new TreeNode(1);
    Codec c;
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    dfs(c.deserialize(c.serialize(root)));
    return 0;
}
