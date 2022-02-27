// solution using graph


#include <bits/stdc++.h>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;






/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
        class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
        };

***********************************************************/

BinaryTreeNode<int> * getNode(BinaryTreeNode<int> * root , int target){
    if(!root) return root ;
    if(root->data == target) return root ;
    BinaryTreeNode<int> * l = getNode(root->left , target) ;
    if(l) return l ;
    BinaryTreeNode<int> * r = getNode(root->right , target) ;
    if(r) return r ;
    return NULL ;
}

void nodesAtDistanceK(BinaryTreeNode<int>* root, int target, int k) {
        unordered_map<BinaryTreeNode<int> * , BinaryTreeNode<int> *> rel ;
        unordered_set<BinaryTreeNode<int> *> visited ;
        queue<BinaryTreeNode<int> *> toProcess ;
        toProcess.push(root) ;
        while(!toProcess.empty()){
            BinaryTreeNode<int> * current = toProcess.front() ;
            toProcess.pop() ;
            if(current->left){
                rel[current->left] = current ;
                toProcess.push(current->left) ;
            }
            if(current->right){
                rel[current->right] = current ;
                toProcess.push(current->right) ;
            }
        }
        BinaryTreeNode<int> * n = getNode(root , target) ;
        toProcess.push(n) ;
        visited.insert(n) ;
        int count = 0 ;
        while(!toProcess.empty()){
            if(count++ == k) break ;
            int n = toProcess.size() ;
            for(int i = 0 ; i < n ; i++){
                BinaryTreeNode<int> * current = toProcess.front() ;
                toProcess.pop() ;
                BinaryTreeNode<int> * top = rel[current] ;
                BinaryTreeNode<int> * left = current->left ;
                BinaryTreeNode<int> * right = current->right ;
                if(left && visited.find(left) == visited.end()){
                    toProcess.push(left) ;
                    visited.insert(left) ;
                }
                if(right && visited.find(right) == visited.end()){
                    toProcess.push(right) ;
                    visited.insert(right) ;
                }
                if(top && visited.find(top) == visited.end()){
                    toProcess.push(top) ;
                    visited.insert(top) ;
                }
            }
        }
        while(!toProcess.empty()){
            cout << toProcess.front()->data << " " ;
            toProcess.pop() ;
        }
        return  ;
    }






BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}