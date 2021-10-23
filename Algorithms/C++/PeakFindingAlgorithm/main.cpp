// link to MIT OC Lecture for 6006
// https://www.youtube.com/watch?v=HtSuA80QTyo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb

// Description: This is a prgoram that finds the peak elements in an array using brute force and divide and conquer algorithms.

// Assumption : There is only one peak element 

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
	pair<Node * , Node * > link ;
} ;

int peak_bruteforce(int * arr , int) ;
int peak_binarysearch_iterative(int * arr , int);
int peak_binarysearch_recursive(int * arr , int);
int peak_binarysearch_recursive_util(int * arr , int , int) ;
Node * insert_node(Node * , int);
int find_max(Node *);


void Run();


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	int n ;
	Node * root = NULL ;
	cin >> n ;
	int arr[n] ;
	f(n){
		int x ;
		cin >> x;
		arr[i] = x;
		root = insert_node(root , x) ;
	}
	cout << "\npeak in the array is (method 1): " << peak_bruteforce(arr , n);
	cout << "\npeak in the array is (method 2): " << peak_binarysearch_iterative(arr , n);
	cout << "\npeak in the array is (method 3): " << peak_binarysearch_recursive(arr , n);
	cout << "\npeak in the array using a BST: " << find_max(root);
	return ;
}

int peak_bruteforce(int * arr , int n) {
	if(n == 0) return INT_MIN ; // corner case 
	if(n == 1) return arr[0] ; // corner case 
	int max = arr[0] ;
	f(n) if(arr[i] > max) max = arr[i] ;
	return max ;
}

int peak_binarysearch_iterative(int * arr , int n) {
	if(n == 0) return INT_MIN ; // corner case 
	if(n == 1) return arr[0] ; // corner case 
	int start = 0 ;
	int end = n - 1;
	if(start < end && arr[start] > arr[start + 1]) return arr[start] ; // corner case 
	if(start < end && arr[end] > arr[end - 1]) return arr[end] ; // corner case 
	while(start < end) {
		int mid = start + (end - start) / 2; 
		if(mid > start && arr[mid] < arr[mid - 1]) end = mid - 1 ;
		else if(mid < end && arr[mid] < arr[mid + 1]) start = mid + 1 ;
		else return arr[mid] ;
	}
	return arr[start] ;
}

int peak_binarysearch_recursive(int * arr , int n){
	if(n == 0) return INT_MIN ; // corner case 
	if(n == 1) return arr[0] ; // corner case 
	return peak_binarysearch_recursive_util(arr , 0 , n-1) ;
}

int peak_binarysearch_recursive_util(int * arr , int start , int end) {
	if(start == end) return arr[start] ; // base condition
	if(start < end && arr[start] > arr[start + 1]) return arr[start] ; // corner case 
	if(start < end && arr[end] > arr[end - 1]) return arr[end] ; // corner case 
	int mid = start + (end - start) / 2;
	if(mid < end && arr[mid] < arr[mid+1]) return peak_binarysearch_recursive_util(arr , mid + 1 , end) ;
	else if (arr[mid - 1] > arr[mid]) return peak_binarysearch_recursive_util(arr, start , mid - 1) ;
	else return arr[mid] ;
}

Node * insert_node(Node * root ,int data) {
	if(!root) {
		Node * newNode = new Node() ;
		newNode->data = data ;
		newNode->link.first = NULL ;
		newNode->link.second = NULL ;
		root = newNode ;
	}
	else if (data > root->data) root->link.second = insert_node(root->link.second , data) ;
	else root->link.first = insert_node(root->link.first , data) ;
	return root ;
}

int find_max(Node * root) {
	if(!(root->link.second)) return root->data ;
	return find_max(root->link.second) ;
}





