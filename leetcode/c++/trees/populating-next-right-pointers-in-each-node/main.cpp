// link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL ;
        queue<Node *> level ;
        level.push(root) ;
        while(!level.empty()){
            int n = level.size() ;
            vector<Node *> l ;
            for(int i = 0 ; i < n ; i++){
                Node * current = level.front() ;
                level.pop() ;
                l.push_back(current) ;
                if(current->left) level.push(current->left) ;
                if(current->right) level.push(current->right) ;
            }
            for(int i = 0 ; i < n -1 ; i++){
                if(l[i]){ 
                    l[i]->next = l[i+1] ;
                }
            }
            l.clear() ;
        }
        return root ;
    }
};