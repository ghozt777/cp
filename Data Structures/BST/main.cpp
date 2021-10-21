
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


struct Node {
	int data ; 
	Node * left;
	Node * right;
};

struct BSTNode {
	int data;
	pair<BSTNode* , BSTNode*> link;
};

Node * insert_node(Node* , int);
BSTNode * insert(BSTNode* , int);
bool search_node(Node* , int);
bool search_bst(BSTNode * , int);

void Run();


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

	search_node(root ,15) ? cout << "True\n" : cout << "False\n";
	search_node(root ,5) ? cout << "True\n" : cout << "False\n";
	search_node(root ,9) ? cout << "True\n" : cout << "Flase\n";
	search_node(root ,30) ? cout << "True\n" : cout << "False\n";
	search_node(root ,10) ? cout << "True\n" : cout << "False\n";
	search_node(root ,69) ? cout << "True\n" : cout << "False\n";

	cout << "\nNew BST Structure:\n";
	root_bst = insert(root_bst , 90);
	root_bst = insert(root_bst , 31);
	root_bst = insert(root_bst , 62);
	root_bst = insert(root_bst , 69);
	root_bst = insert(root_bst , 19);
	root_bst = insert(root_bst , 19);
	root_bst = insert(root_bst , 19);
	root_bst = insert(root_bst , 10);

	search_bst(root_bst , 10) ? cout << "True\n" : cout << "False\n" ;
	search_bst(root_bst , 90) ? cout << "True\n" : cout << "False\n" ;
	search_bst(root_bst , 18) ? cout << "True\n" : cout << "False\n" ;
	search_bst(root_bst , 69) ? cout << "True\n" : cout << "False\n" ;
	search_bst(root_bst , 62) ? cout << "True\n" : cout << "False\n" ;


	return ;
}


Node *  insert_node(Node * root , int x) {
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

BSTNode * insert(BSTNode * root , int data){
	if(!root){
		BSTNode * newNode = new BSTNode() ; 
		newNode->data = data;
		newNode->link.first = NULL;
		newNode->link.second = NULL;
		return newNode;
	}
	else if(data <= root->data)
		root->link.first = insert(root->link.first , data);
	else 
		root->link.second = insert(root->link.second , data);
	return root;
}

bool search_bst(BSTNode * root , int target) {
	if(!root) return false;
	if(root->data == target) return true;
	else if(target <= root->data) return search_bst(root->link.first , target);
	else 
		return search_bst(root->link.second , target);
}

bool search_node(Node* root , int x) {
	if(!root) return false;
	if(root->data == x) return true;
	else if (x <= root->data) return search_node(root->left , x);
	else return search_node(root->right , x);
}


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

	/*
		Given number of nodes find the height of a perfect binary tree with the same number of nodes:
		Sol: 
			if n = number of nodes and h = height of the tree , 
				we know , 

					=> n = 2^(h+1) - 1
					=> (n+1) = 2^(h+1)
					taking log both sides:
					=> log(n+1) = h+1 
					NOTE: here log(x) = log(x) / log(2) or log with base 2
					=>h = log(n+1) - 1 = height of the tree
		
		Also Height of a complete Binary Tree = floor(log(n)) where n is the number of nodes and log is log with base 2

			=> h = floor(log(n))

		Minimum height of a tree with n nodes is one which is as densly packed as possible or a Strict Binary Tree

		Therefore , minimum height of a tree with n nodes is 
			h = floor(log(n+1))
			and maximum height possible is (n+1)

	Time Complexity for Operation is O(h) where h is the height of the tree
	Therefore for a strict binary tree is O(log(n)) and for a tree with (n+1) height iits O(n).
	Hence a Sttrict Binary Tree offers a better time complexity 

	Balanced Binary Tree: Difference between height of left and right subtree for every node is not more than 1 
		diff = | h(left) - h(right) |  

	Height of an empty tree = -1
	Height of a tree with 1 node = 0
	----------------------------------------------------------
	----------------------------------------------------------
	
	Binary Search Tree : Offers quick search and quick update
 	Can be implemented using arrays or linked lists

 	Time Complexities:
 	For Arrays:
 		Search: O(n) for unsorted O(log(n)) for sorted
 		Insert: O(1) if not filled O(n) if sorted array
 		Insert: O(n) if array is filled
 		Delete: O(n)

 	For Linked List:
 		Search: O(n)
 		Insert: O(1) for push_front O(n) for push_back
 		Delete: O(n)

 	For BST:
 		Insert: O(log(n))
 		Search: O(log(n))
 		Delete: O(log(n))
 		In worst case cost of all the operations is O(n) 
 		This worst case condidition can be avoided by making sure that the tree is always balanced.

 	What is a Binary Search Tree ?
 	Ans: A Binary Search Tree is a Binary Tree in which for each node , vakue of all the nodes in the left subtree is lesser or equal than valuef of all the nodes in right subtree.
 				    🌳 <--- root
 					|
 			-----------------
 		    |	            |
 		    |               |
 		    |	            |
		    🪴              🪴 <----- BSTs
		Left Subtree      Right Subtree
	 (lesser or equal)      (greater)
 	
	*/

