
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
	int key ;
	Node * left ;
	Node * right ;
	Node(){
		left = right = NULL ;
		key = 0 ;
	}
	Node(int key){
		this->key = key ;
		left = right = NULL ;
	}
} ;



// ---------------- UTIL FUNCS -------------------------------------------


// ---------------- TRAVERSAL OPS ----------------------------------------

// Time Complexity: O(n) n = number of nodes
// Auxiliary Space : O(h) h = height of the tree

// Depth First Traversals

void inorder(Node * root) {
	if(!root) return ;
	inorder(root->left) ;
	cout << root->key << " " ;
	inorder(root->right) ;
}

void preorder(Node * root) {
	if(!root) return ;
	cout << root->key << " " ;
	preorder(root->left) ;
	preorder(root->right) ;
}

void postorder(Node * root) {
	if(!root) return ;
	postorder(root->left) ;
	postorder(root->right) ;
	cout << root->key << " " ;
}

// Breath First Traversal

void levelorder(Node * root) { // Level Order Traversal
	/*

	This is one way to do it but is very inefficeint :( 
	TC : O(n+ n*h) = O(n*h)

	for(int i = 0 ; i < height(root) ; i++){
		cout << "at " << i << "th level : " ;
		printK(root , i) ;
		cout << "\n" ;
	}

	*/

	// recursion can't be used to solve this problem
	// But we can use queue to solve it

	// TC : Theta(n) 
	// SC : Theta(width of the tree) || if balanced tree : Theta(n)

	if(!root) return ;

	queue<Node *> q ;
	q.IN(root) ;
	while(!q.empty()){
		Node * curr = q.front() ;
		q.pop() ;
		cout << curr->key << " " ;
		if(curr->left) q.IN(curr->left) ;
		if(curr->right) q.IN(curr->right) ;
	} 
}

void printLevels(Node * root){
	// TC : O(n+h) = O(n) 
	// SC : Theta(width of the tree)
	if(!root) return ;
	queue<Node *> q ;
	q.IN(root) ;
	q.push(NULL) ; // using NULL pointer to denote the end of a level
	while(q.size() > 1){ // we are usinfg size instead of checking if the queue is empty beacuse at the end only one element will be left behind and using empty() as a condition to check for the loop will create an infinite loop
		Node * curr = q.front() ;
		q.pop();
		if(curr){ 
			cout << curr->key << " " ;
			if(curr->left) q.IN(curr->left) ; 
			if(curr->right) q.IN(curr->right) ; 
		}
		else{ 
			cout << "\n" ;
			q.push(NULL) ; // adding null as reaching null indicates that we reached end of the previous level and hence all the elements of the next level are currently in the queue and hence we can add a NULL pointer after all the elements of the next level 
		}
	}
}

void printLevels_v2(Node * root){
	if(!root) return ;
	queue<Node *> q ;
	q.IN(root) ;
	while(!q.empty()){
		int count = q.size() ;
		for(int i = 0 ; i < count ; i++){ // don't replace count with q.size() as q.size() changes dynamically and then we wont't get the desired result : we need to hold on to the count value of q when it entered the loop not when we add nodes to it .
			Node * curr = q.front() ;
			q.pop() ;
			cout << curr->key << " " ;
			if(curr->left) q.IN(curr->left) ;
			if(curr->right) q.IN(curr->right) ;
		}
		cout << "\n" ;
	}
}

// ------------------ HEIGHT AND SIZE --------------------------------------------
// height of a tree is the max distance between the root node and any of the leaves
// Time Complexity : O(n)
// Auxiliary Space : O(h) 

int height(Node * root) {
	if(!root) return 0 ;
	return 1 + max(height(root->left) , height(root->right)) ;
}

int size(Node * root) { // returns the number of nodes in the tree
	if(!root) return 0 ;
	return 1 + size(root->left) + size(root->right) ;
}


// ---------- PRINT NODES AT DISTANCE K -----------------------------------

// i.e. For a Given value of k :
//	-> print all the nodes in the (k+1)th level for 1 based indexing
//	-> print all the nodes at the kth level for 0 based indexing

// TC : Theta(n) Avg case , worst case : O(n) 
// SC : Worst Case O(h) , avg case : Theta(h)

void printK(Node * root , int k){
	if(!root) return ;
	if(k == 0) cout << root->key << " " ;
	else {
		printK(root->left , k - 1) ;
		printK(root->right , k - 1) ;
	}
}


// ------------------------------------------------------------------------

int maxVal(Node * root) { // returns the max value in the binary tree
	if(!root) return INT_MIN ; // if root is null returns INT_MIN
	if(!root->left&&!root->right) return root->key ; // stop at leaf node 
	return max(root->key , max(maxVal(root->left) , maxVal(root->right))) ;
} 

void printLeftNodesUtil(Node * root , int & maxLevel , int level){
	if(!root) return ;
	if(maxLevel < level){
		cout << root->key << " " ;
		maxLevel = level ;
	}
	// if we dont pass maxLevel by reference it will suffer from stale state clousre and is going to produce an errenuous output as changes made in particualr call might not get refected if we pass it by value 
	printLeftNodesUtil(root->left, maxLevel, level + 1) ;
	printLeftNodesUtil(root->right, maxLevel , level + 1) ;
}

void printLeftNodes(Node * root) {
	// TC : O(n) 
	// SC : Theta(h) 
	cout << "recursive:\n" ;
	int maxLevel = 0 ;
	printLeftNodesUtil(root , maxLevel , 1) ;
}

void printLeftNodesIterative(Node * root) {
	cout << "iterative:\n" ;
	if(!root) return ;
	queue<Node *> q ;
	q.IN(root) ;
	while(!q.empty()){
		int c = q.size() ;
		for(int i = 0 ; i < c ; i++){
			Node * curr = q.front() ;
			q.pop() ;
			if(i == 0) cout << curr->key << " " ;
			if(curr->left) q.IN(curr->left) ;
			if(curr->right) q.IN(curr->right) ;
		}
	}
}

bool isChildrenSum(Node * root) { // checks if at every node the value at the root = sum of the value of its children : if a child is null then it can be considered as 0
	if(!root) return true ;
	if (!root->left&&!root->right) return true ;
	int sum = 0 ; 
	if(root->left) sum += root->left->key ;
	if(root->right) sum += root->right->key ;
	return root->key == sum && isChildrenSum(root->left) && isChildrenSum(root->right) ;
}

bool isBalanced_bruteforce(Node * root) { // if the height difference between left subtree and right subtree is less than 2 then its a balanced tree otherwise its not balanced
// TC : O(n^2)
	if(!root) return true ;
	return abs(height(root->left) - height(root->right)) < 2 && isBalanced_bruteforce(root->left) && isBalanced_bruteforce(root->right) ;
}

int isBalancedUtil(Node * root) {
	// this util function calculates the height of the subtress as well as checks if the trees are balanced or not : if not it returns -1 else returns height of the subtree
	if(!root) return 0 ;
	int leftH = isBalancedUtil(root->left) ;
	if(leftH == -1) return -1 ;
	int rightH = isBalancedUtil(root->right) ;
	if(rightH == -1) return -1 ;
	if(abs(leftH - rightH) >= 2) return -1 ;
	else return max(leftH , rightH) + 1 ;
}

bool isBalanced(Node * root) {
	// optimized solution that takes only O(n) time
	return isBalancedUtil(root) != -1 ;
}

int width(Node * root){
	// width = max number of nodes at any given level
	// TC : O(n) 
	// SC : Theta(max width of tree)
	if(!root) return 0 ;
	queue<Node *> q ;
	q.IN(root) ;
	int ans = 1 ;
	while(!q.empty()){
		int count = q.size() ;
		ans = max(ans , count) ;
		f(count){
			Node * curr = q.front() ;
			q.pop() ;
			if(curr->left) q.IN(curr->left) ;
			if(curr->right) q.IN(curr->right) ;
		}
	}
	return ans ;
}

void printList(Node * head) {
	while(head){cout << head->key << " " ; head = head->right ;}
}


Node *BTToDLL(Node *root){
    if(root==NULL)return NULL;
    static Node* prev = NULL;
    Node *head=BTToDLL(root->left);
    if(prev==NULL){head=root;}
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTToDLL(root->right);
    return head;
}

// ------------------------------------------------------------------------


struct Nodec {
	char c ;
	Nodec * right ;
	Nodec * left ;
	Nodec(char c){this->c = c ; this->left = this->right = NULL ;} 
} ;

void inorder(Nodec * root){
	if(!root) return ;
	inorder(root->left) ;
	cout << root->c ;
	inorder(root->right) ;
}

void printName() {
	Nodec * root = new Nodec('h') ;
	Nodec * l = new Nodec('g') ;
	Nodec * r = new Nodec('z') ;
	Nodec * rl = new Nodec('o') ;
	Nodec * rr = new Nodec('t') ;
	root->left = l ;
	root->right = r ;
	r->left = rl ;
	r->right = rr ;
	cout << "\n" ;
	inorder(root) ;
	cout << "\n " ;
}


void Run();
void printArray(int[] , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {

	// creating an empty tree 
	Node * root ;

	// manually creating a tree 

	root = new Node(10) ;
	Node * l1 = new Node(20) ;
	Node * r1 = new Node(30) ;
	Node * r1l = new Node(40) ;
	Node * r1r = new Node(50) ;
	root->left = l1 ;
	root->right = r1 ;
	r1->left = r1l ;
	r1->right = r1r ;

	// traversing the tree in three different ways :
	cout << "inorder: \n" ;
	inorder(root) ; // 20 10 40 30 50 

	cout << "\npreorder: \n" ;
	preorder(root) ; // 10 20 30 40 50 

	cout << "\npostorder: \n" ;
	postorder(root) ; // 20 40 50 30 10 

	cout << "\nheight of the tree = " << height(root) << "\n" ;

// This is one way to do level order traversal using the height of the tree and levelK functions
	for(int i = 0 ; i < height(root) ; i++){
		cout << "at " << i << "th level : " ;
		printK(root , i) ;
		cout << "\n" ;
	}

	delete(root) ;
	delete(l1) ;
	delete(r1) ;
	delete(r1l) ;
	delete(r1r) ;

	root = new Node(10) ;
	l1 = new Node(20) ;
	r1 = new Node(30) ;
	Node * l1l = new Node(40) ;
	Node * l1r = new Node(80) ;
	r1r = new Node(70) ;
	Node * r1rr = new Node(50) ;
	root->left = l1 ;
	root->right = r1 ;
	l1->left = l1l ;
	l1->right = l1r ;
	r1->right = r1r ;
	r1r->right = r1rr ;

	cout << "\nCreating a new tree and deleting the old one ...\n" ;
	cout << "Height of the new tree = " << height(root) << "\n";

	for(int i = 0 ; i < height(root) ; i++){
		cout << "at " << i << "th level : " ;
		printK(root , i) ;
		cout << "\n" ;
	}

	cout << "\nlevel order traversal: \n" ;
	levelorder(root) ;
	cout << "\nprinting the tree libe by line:\n" ;
	printLevels(root) ;

	cout << "\nprinting the tree libe by line(version 2):\n" ;
	printLevels_v2(root) ;

	cout << "number of nodes = " << size(root) <<"\n" ;
	cout << "max value in the tree is = " << maxVal(root) ;
	cout << "\nPrinting the left nodes (of tree 1) : \n" ;
	Node * t = new Node(30) ;
	Node * tr = new Node(50) ;
	Node * trl = new Node(60) ;
	Node * trr = new Node(10) ;
	t->right = tr ;
	tr->left = trl ;
	trl->right = trr ; 
	printLeftNodes(t) ;
	cout << "\n" ;
	printLeftNodesIterative(t) ;
	cout << "\nPrinting the left nodes (of tree 2) : \n" ;
	printLeftNodes(root) ;
	cout << "\n" ;
	printLeftNodesIterative(root) ;
	cout << "\nDoes Tree 1 follow children sum property ? : " ;
	isChildrenSum(t) ? cout << "YES\n" : cout << "NO\n" ;
	cout << "\nDoes Tree 2 follow children sum property ? : " ;
	isChildrenSum(root) ? cout << "YES\n" : cout << "NO\n" ;
	Node * t1 = new Node(1) ;
	Node * t2 = new Node(2) ;
	Node * t3 = new Node(3) ;
	Node * t4 = new Node(4) ;
	Node * t5 = new Node(5) ;
	t1->left =t2 ;
	t1->right = t3 ;
	t3->left = t4 ;
	t3->right = t5 ;
	cout << "\nTree 3:\n" ;
	printLevels(t1) ;
	cout << "\nusing brute force:\n" ;
	cout << "\nIs Tree 1 balanced ? : " ;
	isBalanced_bruteforce(t) ? cout << "YES\n" : cout << "NO\n" ;
	cout << "\nIs Tree 2 balanced ? : " ;
	isBalanced_bruteforce(root) ? cout << "YES\n" : cout << "NO\n" ;
	cout << "\nIs Tree 3 balanced ? : " ;
	isBalanced_bruteforce(t1) ? cout << "YES\n" : cout << "NO\n" ;
	cout << "\nusing efficient solution:\n" ;
	cout << "\nIs Tree 1 balanced ? : " ;
	isBalanced(t) ? cout << "YES\n" : cout << "NO\n" ;
	cout << "\nIs Tree 2 balanced ? : " ;
	isBalanced(root) ? cout << "YES\n" : cout << "NO\n" ;
	cout << "\nIs Tree 3 balanced ? : " ;
	isBalanced(t1) ? cout << "YES\n" : cout << "NO\n" ;
	cout << "width of tree 1 = " << width(t) << "\n" ;
	cout << "width of tree 2 = " << width(root) << "\n" ;
	cout << "width of tree 3 = " << width(t1) << "\n" ;
	Node * head = BTToDLL(root) ;
	cout << "after tree 2 gets converted into a Doubly Linked List:\n" ;
	printList(head) ;
	printName();
	return ;
}



/*
	Trees can be used to reprsent hierarchical data .
	Eg Folder structures , Company positions 
	Applications : 
		1. Folder Structure
		2. XML / HTML Documents
		3. AST duirng lexing in Javascript
		4. In OOP(Inheritance)
		5. BST 
		5. Binary Heap (used to represent priority queue)
		6. B and B+ Trees in DBMS
		7. Spanning and shortest path trees in Computer Network
		8. Parse Trees in compilaaere
		9. Trie
		10. Suffix Tree
		11. Binary Index Tree 
		12. Segment Tree

*/

/*
	Binary Tree : 
	In Binary Tree the max degree(number of children) is 2 . 
	They can be implemented using arrays or linked structure
	Use to implement some of the most popular tree based data structures: BST and Binary Heaps

*/

/*
	Tree Traversals: 
		1. Breath First or Level Order (read the root first then read its children from left to right)
		2. Depth First : (It includes three tasks: process the root , process the left subtree , process the right subtree)
		Therefore depending on the order of these tasks there are 3! = 6 number of ways it can be done :
		Out of them the three most popular are :
			a. Inorder (Left -> Root -> Right)
			b. Preorder (Root -> Left -> Right)
			c. Postorder (Left -> Right -> Root)

*/



void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


