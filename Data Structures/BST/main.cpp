
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)

void Run();

// ------------------------------------------------------
//  Binary Search Trees 
// ------------------------------------------------------

struct Node {
	int data ; 
	Node * left;
	Node * right;
};
// much simpler structure
struct BSTNode {
	int data;
	pair<BSTNode* , BSTNode*> link;
};

// ------------ : Functions : --------------------------------

Node * insert_node(Node* , int);
BSTNode * insert_node(BSTNode* , int);
pair<int , int> min_max(Node *);
pair<int , int> min_max(BSTNode *);
Node * delete_node(Node * , int);
Node * find_min_address(Node *);
BSTNode * delete_node(BSTNode * , int);
BSTNode * find_min_address(BSTNode *);
bool search_bst(Node* , int);
bool search_bst(BSTNode * , int);
int find_min(Node *);
int find_min(BSTNode *);
int find_max(Node *);
int find_max(BSTNode *);
int height(Node*);
int height(BSTNode*);
void print_in_sorted(Node*);
void print_in_sorted(BSTNode*);
void print_tree(Node*);
void print_tree(BSTNode*);
bool isBinarySearchTree(Node*);
bool isBinarySearchTree(BSTNode*);
bool isBST(Node*); // faster than the upper version
bool isBST(BSTNode *);
bool isBSTUtil(Node* , int , int);
bool isBSTUtil(BSTNode* , int , int);
bool isSmaller(Node * , int);
bool isGreater(Node * , int);
bool isSmaller(BSTNode * , int);
bool isGreater(BSTNode * , int);

// ----------------: Implementation :--------------------------

Node * insert_node(Node * root , int x) {
	if(!root){
		Node * newNode = new Node();
		newNode->data = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if(x <= root->data)
		root->left = insert_node(root->left , x);
	else 
		root->right = insert_node(root->right ,x);
	return root;
}

BSTNode * insert_node(BSTNode * root , int data){
	if(!root){
		BSTNode * newNode = new BSTNode() ; 
		newNode->data = data;
		newNode->link.first = NULL;
		newNode->link.second = NULL;
		root = newNode;
	}
	else if(data <= root->data)
		root->link.first = insert_node(root->link.first , data);
	else 
		root->link.second = insert_node(root->link.second , data);
	return root;
}

bool search_bst(BSTNode * root , int target) {
	if(!root) return false;
	if(root->data == target) return true;
	else if(target <= root->data) return search_bst(root->link.first , target);
	else 
		return search_bst(root->link.second , target);
}

bool search_bst(Node* root , int x) {
	if(!root) return false;
	if(root->data == x) return true;
	else if (x <= root->data) return search_bst(root->left , x);
	else return search_bst(root->right , x);
}


pair<int , int> min_max(Node * root){
	if(!root) return make_pair(-1 , -1);
	return make_pair(find_max(root) , find_min(root));
}

pair<int , int> min_max(BSTNode * root){
	if(!root) return make_pair(-1 , -1);
	return make_pair(find_max(root) , find_min(root));
}

int find_min(Node * root){
	if(!root->left) return root->data;
	else return find_min(root->left);
}

int find_max(Node * root){
	if(!root->right) return root->data;
	else return find_max(root->right);
}

int find_min(BSTNode * root){
	if(!root->link.first) return root->data;
	else return find_min(root->link.first);
}

int find_max(BSTNode * root){
	if(!root->link.second) return root->data;
	else return find_max(root->link.second);
}

void print_in_sorted(Node* root){
	// this uses the inorder traversal of deapth first algorithm
	// Time Complexity : O(n)
	// Space Complexity: O(log(n)) Best ? Avg Case
	//					 O(n) :  Worst Case
	if(!root) return ;
	print_in_sorted(root->left);
	cout << root->data << " ";
	print_in_sorted(root->right);
}

void print_in_sorted(BSTNode* root){
	// this uses the inorder traversal of deapth first algorithm
	if(!root) return ;
	print_in_sorted(root->link.first);
	cout << root->data << " ";
	print_in_sorted(root->link.second);
}

int height(Node * root){
	if(!root) return -1; // height of an empty tree is -1
	return max(height(root->left) , height(root->right)) + 1;
}

int height(BSTNode * root){
	if(!root) return -1; // height of an empty tree is -1
	return max(height(root->link.first) , height(root->link.second)) + 1;
}

void print_tree(Node * root){
	// this uses breath first algorithm of level order traversal
	queue<Node *> q;
	if(!root) return;
	q.IN(root);
	while(!q.empty()){
		Node * curr = q.front();
		if(curr->left)q.IN(curr->left);
		if(curr->right)q.IN(curr->right);
		cout << curr->data << " ";
		q.pop();
	}
}

void print_tree(BSTNode * root){
	// this uses breath first algorithm of level order traversal
	// Time Complexity : O(n) n = no . of nodes
	// Space Complexity : O(1) best  ; O(n) : worst / avg 
	queue<BSTNode *> q;
	if(!root) return;
	q.IN(root);
	while(!q.empty()){
		BSTNode * curr = q.front();
		if(curr->link.first)q.IN(curr->link.first);
		if(curr->link.second)q.IN(curr->link.second);
		cout << curr->data << " ";
		q.pop();
	}
}

bool isBinarySearchTree(Node * root){
	if(!root) return true;
	if(isSmaller(root->left , root->data) && isGreater(root->right , root->data) && isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
	return true;
	else return false;
}

bool isSmaller(Node * root , int target){
	if(!root) return true;
	if(root->data <= target && isSmaller(root->left , target) && isSmaller(root->right , target))
		return true;
	else return false;
}

bool isGreater(Node * root , int target){
	if(!root) return true;
	if(root->data > target && isGreater(root->left , target) && isGreater(root->right , target))
		return true;
	else return false;
}

bool isBinarySearchTree(BSTNode * root){
	if(!root) return true;
	if(isSmaller(root->link.first , root->data) && isGreater(root->link.second , root->data) && isBinarySearchTree(root->link.first) && isBinarySearchTree(root->link.second))
	return true;
	else return false;
}

bool isSmaller(BSTNode * root , int target){
	if(!root) return true;
	if(root->data <= target && isSmaller(root->link.first , target) && isSmaller(root->link.second , target))
		return true;
	else return false;
}

bool isGreater(BSTNode * root , int target){
	if(!root) return true;
	if(root->data > target && isGreater(root->link.first , target) && isGreater(root->link.second , target))
		return true;
	else return false;
}

bool isBST(Node * root){
	return isBSTUtil(root , INT_MAX , INT_MIN);
}

bool isBSTUtil(Node * root , int upper_bound , int lower_bound){
	// base case:
	if(!root) return true;
	// check if the data is int the range or not
	if(root->data <= upper_bound && root->data >= lower_bound && isBSTUtil(root->left , root->data , lower_bound) && isBSTUtil(root->right , upper_bound , root->data))
		return true;
	else return false;
}

bool isBST(BSTNode * root){
	return isBSTUtil(root , INT_MAX , INT_MIN);
}

bool isBSTUtil(BSTNode * root , int upper_bound , int lower_bound){
	// base case:
	if(!root) return true;
	// check if the data is int the range or not
	if(root->data <= upper_bound && root->data >= lower_bound && isBSTUtil(root->link.first , root->data , lower_bound) && isBSTUtil(root->link.second , upper_bound , root->data))
		return true;
	else return false;
}

Node * find_min_address(Node * root) {
	if(!(root->left)) return root ;
	return find_min_address(root->left);
}

Node * delete_node(Node * root , int target) {
	if(!root) return root ;
	else if(target < root->data) root->left = delete_node(root->left , target);
	else if(target > root->data) root->right = delete_node(root->right , target);
	else {
		// we found the node 
		// CASE 1 : When the node to delete is a leaf node 
		if(!(root->right && root->left)){
			delete root ; // This causes the root to be a dangling pointer
			root = NULL ; // fixing it !
			return root ;
		}

		// CASE 2 : When the node has only 1 child
		if(!(root->left)){
			Node * temp = root ;
			root = root->right ;
			delete temp ;
		}
		if(!(root->right)){
			Node * temp = root ;
			root = root->left ;
			delete temp ;
		}

		// CASE 3 : When the root has 2 children
		if(root->left && root->right) {
			Node * min = find_min_address(root->right) ;
			root->data = min->data ;
			root->right = delete_node(root->right , min->data) ;
			return root ;
		}
	}
	return root ;
}

BSTNode * find_min_address(BSTNode * root) {
	if(!(root->link.first)) return root ;
	return find_min_address(root->link.first);
}

BSTNode * delete_node(BSTNode * root , int target) {
	if(!root) return root ;
	else if(target < root->data) root->link.first = delete_node(root->link.first , target);
	else if(target > root->data) root->link.second = delete_node(root->link.second , target);
	else {
		// we found the node 
		// CASE 1 : When the node to delete is a leaf node 
		if(!(root->link.second && root->link.first)){
			delete root ; // This causes the root to be a dangling pointer
			root = NULL ; // fixing it !
			return root ;
		}

		// CASE 2 : When the node has only 1 child
		if(!(root->link.first)){
			BSTNode * temp = root ;
			root = root->link.second ;
			delete temp ;
		}
		if(!(root->link.second)){
			BSTNode * temp = root ;
			root = root->link.first ;
			delete temp ;
		}

		// CASE 3 : When the root has 2 children
		if(root->link.first && root->link.second) {
			BSTNode * min = find_min_address(root->link.second) ;
			root->data = min->data ;
			root->link.second = delete_node(root->link.second , min->data) ;
			return root ;
		}
	}
	return root ;
}

// Notes to refer: 


//-------------------------------------------------------
	//-------------------------------------------------------

	// TREE DATA STRUCTURE
	// a tree is a non-linear Data Structure based on hierarchy
	// a tree is composed of nodes 
	// and each node is ade up of the data component and may or may not contain one one or more than one node below it called children
	// the topmost node is called the root
	// a parent and its children are connected throught links
	// children of the same parent are called siblings
	// all the nodes which don't have their own children are called leaf node
	// its a recursive data structure
	// A tree is divided into subtress where a root contains subtrees as its children
	// The recursive structure looks like
	/*				🌳--- > root
					/|  |
				   / |  | 
				  /  |  |
				 /   |  |
			...	🪴  🪴  🪴 .... subtrees
				T1  T2  T3

	*/ 

	// In a tree with n nodes there are (n-1) edges or links (since in a valid tree there is only one incoming edge or link except for the root node i.e. n - 1)

	// Depth of x node = Number of edges in path from root to x ot the length of the path from root to x

	// Height of x node = Number of edges in longest path from x to a leaf. (Leaf Node = Node with 0 children)

	// Height of the tree is the height of the root node

	// In a Binary Tree a node can have at most 2 children
	/* Applications of Tree DS:  
		1. Storing natural Hierarchical data Eg: The File System in OS
		2. Organizing Data: for quick searching , insertion , and deletion. Eg: BST provides log(n) time for searching
		3. Used in Network routing algorithms
		4. Trie Data Structure
	*/

	// A strict Binary Tree contains nodes that have either 2 or 0 children. 
	// A Binary Tree is called a Complete Binary Tree po Perfect Binary Tree if all levels except possibly the last are completely filled 
	// Max Number of nodes at level i = 2^i
	// Levels start from 0 : L-0 , L-1, l-2 ..
	/*
		Max Number of nodes in a Binary Tree with height h = 2^0 + 2^1 + 2^2 + 2^3 + ..... 2^h
		= 2^(h+1) - 1 
		= 2^(number of levels) - 1
	*/

	
	// 	Given number of nodes find the height of a perfect binary tree with the same number of nodes:
	// 	Sol: 
	// 		if n = number of nodes and h = height of the tree , 
	// 			we know , 

	// 				=> n = 2^(h+1) - 1
	// 				=> (n+1) = 2^(h+1)
	// 				taking log both sides:
	// 				=> log(n+1) = h+1 
	// 				NOTE: here log(x) = log(x) / log(2) or log with base 2
	// 				=>h = log(n+1) - 1 = height of the tree
		
	// 	Also Height of a complete Binary Tree = floor(log(n)) where n is the number of nodes and log is log with base 2

	// 		=> h = floor(log(n))

	// 	Minimum height of a tree with n nodes is one which is as densly packed as possible or a Strict Binary Tree

	// 	Therefore , minimum height of a tree with n nodes is 
	// 		h = floor(log(n+1))
	// 		and maximum height possible is (n+1)

	// Time Complexity for Operation is O(h) where h is the height of the tree
	// Therefore for a strict binary tree is O(log(n)) and for a tree with (n+1) height iits O(n).
	// Hence a Sttrict Binary Tree offers a better time complexity 

	// Balanced Binary Tree: Difference between height of left and right subtree for every node is not more than 1 
	// 	diff = | h(left) - h(right) |  

	// Height of an empty tree = -1
	// Height of a tree with 1 node = 0
	// ----------------------------------------------------------
	// ----------------------------------------------------------
	
	// Binary Search Tree : Offers quick search and quick update
 // 	Can be implemented using arrays or linked lists

 // 	Time Complexities:
 // 	For Arrays:
 // 		Search: O(n) for unsorted O(log(n)) for sorted
 // 		Insert: O(1) if not filled O(n) if sorted array
 // 		Insert: O(n) if array is filled
 // 		Delete: O(n)

 // 	For Linked List:
 // 		Search: O(n)
 // 		Insert: O(1) for push_front O(n) for push_back
 // 		Delete: O(n)

 // 	For BST:
 // 		Insert: O(log(n))
 // 		Search: O(log(n))
 // 		Delete: O(log(n))
 // 		In worst case cost of all the operations is O(n) 
 // 		This worst case condidition can be avoided by making sure that the tree is always balanced.

 // 	What is a Binary Search Tree ?
 // 	Ans: A Binary Search Tree is a Binary Tree in which for each node , vakue of all the nodes in the left subtree is lesser or equal than valuef of all the nodes in right subtree and the root node.
 // 				    🌳 <--- root
 // 					|
 // 			-----------------
 // 		    |	            |
 // 		    |               |
 // 		    |	            |
		// 	    🪴              🪴 <----- BSTs
	// 	Left Subtree      Right Subtree
	//  (lesser or equal)      (greater)
 	
 /*
	Tree Traversal: process of visiting each node in the tree exactly once in some order

	Visit: Reading / Processing data in a node

	Tree Traversal Algorithms can be classified into two categories:
		1. Breath First : Level Order Traversal 
		2. Depth First : Preorder : root -> left subtree -> right subtree
						 Inorder: left -> root -> right
						 PostOrder: left -> right -> root
		// Inorderd traversal of a BST gives the elements in a sorted fashion



 */

// ---------------------------------------------------------------
// ---------------------------------------------------------------
// ---------------------------------------------------------------

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	Node * root = NULL;
	BSTNode * root_bst = NULL;
	root = insert_node(root , 10);
	root = insert_node(root , 20);
	root = insert_node(root , 15);
	root = insert_node(root , 9);
	root = insert_node(root , 30);

	cout <<  "Elements of the first tree in sorted order: \n";
	print_in_sorted(root);
	cout << "\n\n";

	cout << " 15 in tree 1 ? " ; search_bst(root ,15) ? cout << "True\n" : cout << "False\n";
	cout << " 5 in tree 1 ? " ; search_bst(root ,5) ? cout << "True\n" : cout << "False\n";
	cout << " 9 in tree 1 ? " ; search_bst(root ,9) ? cout << "True\n" : cout << "Flase\n";
	cout << " 30 in tree 1 ? " ; search_bst(root ,30) ? cout << "True\n" : cout << "False\n";
	cout << " 10 in tree 1 ? " ; search_bst(root ,10) ? cout << "True\n" : cout << "False\n";
	cout << " 69 in tree 1 ? " ; search_bst(root ,69) ? cout << "True\n" : cout << "False\n";

	cout << "\nNew BST Structure:\n";
	root_bst = insert_node(root_bst , 90);
	root_bst = insert_node(root_bst , 31);
	root_bst = insert_node(root_bst , 62);
	root_bst = insert_node(root_bst , 69);
	root_bst = insert_node(root_bst , 19);
	root_bst = insert_node(root_bst , 19);
	root_bst = insert_node(root_bst , 19);
	root_bst = insert_node(root_bst , 10);

	cout <<  "Elements of the second tree in sorted order: \n";
	print_in_sorted(root_bst);
	cout << "\n\n";

	cout << " 10 in tree 2 ? " ; search_bst(root_bst , 10) ? cout << "True\n" : cout << "False\n" ;
	cout << " 90 in tree 2 ? " ; search_bst(root_bst , 90) ? cout << "True\n" : cout << "False\n" ;
	cout << " 18 in tree 2 ? " ; search_bst(root_bst , 18) ? cout << "True\n" : cout << "False\n" ;
	cout << " 69 in tree 2 ? " ; search_bst(root_bst , 69) ? cout << "True\n" : cout << "False\n" ;
	cout << " 62 in tree 2 ? " ; search_bst(root_bst , 62) ? cout << "True\n" : cout << "False\n" ;
	pair<int , int> node_min_max = min_max(root);
	pair<int , int> bst_min_max = min_max(root_bst);

	cout << "\nMax and Min in first node: \n";
	cout << "max: " << node_min_max.first << " min: " << node_min_max.second << "\n";
	cout << "\nMax and Min in second node: \n";
	cout << "max: " << bst_min_max.first << " min: " << bst_min_max.second << "\n";

	cout << "\nHeight of first tree: " << height(root);
	cout << "\nHeight of second tree: " << height(root_bst);
	cout << "\n\n";
	cout << "The first tree look like:\n";
	print_tree(root);
	cout << "\nThe second tree looks like:\n";
	print_tree(root_bst);
	cout << "\n\ncheck if the first tree is a binary search tree:\n";
	isBinarySearchTree(root) ? cout << "True" : cout << "False" ;
	cout << "\n\ncheck if the second tree is a binary search tree:\n";
	isBinarySearchTree(root_bst) ? cout << "True" : cout << "False" ;
	cout << "\n\ncheck if the first tree is a binary search tree: using the faster approach\n";
	isBST(root) ? cout << "True" : cout << "False" ;
	cout << "\n\ncheck if the second tree is a binary search tree: using the faster approach\n";
	isBST(root_bst) ? cout << "True" : cout << "False" ;
	cout << "\n\n";
	cout << "Deleting Node from the 1st Tree with value 20 : \n";
	root = delete_node(root , 20) ; 
	cout << "\nPrinting the tree: \n" ;
	print_tree(root) ;
	cout << "\nDeleting 19 from the second tree:\n" ;
	root_bst = delete_node(root_bst , 19) ;
	cout << "\nPrinting the tree:\n";
	print_tree(root_bst);

	return ;
}




