// link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
#include "./../TreeNode.cpp"
#include<bits/stdc++.h>
using namespace std ;

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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        if(!root) return ans ;
        queue<TreeNode *> q ;
        q.push(root) ;
        bool alter = false ;
        while(!q.empty() ){
						int n = q.size() ;
						vector<int> level(n) ;
						for(int i = 0 ; i < n ; i++){
								TreeNode * current = q.front() ;
								q.pop() ;
								level.push_back(current->val) ;
								if(current->left) q.push(current->left) ;
								if(current->right) q.push(current->right) ;
						}
						alter = !alter ;
            ans.push_back(level) ;
        }
        return ans ;
    }
};



int main(){
	
		Solution s ;
		
		TreeNode * root = new TreeNode(1) ;
		root->left = new TreeNode(2) ;
		root->right = new TreeNode(3) ;
		root->left->left = new TreeNode(4) ;
		root->right->right = new TreeNode(5) ;
		vector<vector<int>> ans = s.zigzagLevelOrder(root) ;
		for(vector<int> x : ans){
				for(int y : x) cout << y << " " ;
				cout << endl ;
			}
		return 0 ;
}
