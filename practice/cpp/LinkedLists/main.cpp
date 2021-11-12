
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

template<typename T> struct Node {
	T data ;
	Node * next ;

	Node(T x){
		data = x ;
		next = NULL ;
	}

	Node * pb(Node * head , T x){
		Node * newNode = new Node(x) ;
		if(!head) return newNode ;
		else{
			Node * i = head ;
			while(i->next) i = i->next ;
			i->next = newNode ;
		}
		return head ;
	}

	void printLL(Node * head){
	if(!head){
		cout << "[]\n" ;
		return ;
	}
	if(!head->next){
		cout << "[" << head->data << "]\n" ;
		return ;
	}
	cout << "[" << head->data << ", " ;
	head = head->next ;
	while(head->next){
		cout << head->data << ", " ;
		head = head->next ;
	}
	cout << head->data << "]" ;
	cout << "\n" ;
	}
} ;



void Run();


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	// There are three different ways to create an array in c++
	// 1. fixed size in the stack 
	int arr[5] ;
	// 2. in the heap 
	int * arrH = new int[5] ;
	// 3. as vectors of dynamic size 
	vi arrV(5,-1) ;

	// Linked Lists : 
	Node<char> * head = new Node('a') ;
	for(char c = 'b' ; c <= 'g'; c++)
		head = head->pb(head , c) ;
	head->printLL(head) ;

	return ;
}


/*
	Notes :

	Problems associated with array data structrue :
	Arrays store all of its elements as a contagious memory block whereas a Linked Lists stores its elements in random order
	Arrays and Lined Lists are the biggest competitors of each other 
	
	Now the potential problems with arrays : 
	1. We need to preallocate the space 
	2. The problem with vectors is that during insertion if its reaches its size then it needs to create a new array with double its size and then copy all its elements to the newly created one which takes O(n)
	Therefore in some cases it may take O(n) time for insertion(for vectors).
	3. Insertion / Deletion in the middle is costly 
	4. Implementation of Data Structures like Queue and Deque is complex using arrays

*/






void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}




