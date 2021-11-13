// ------------------ LINKED LISTS ------------------------------
#include<bits/stdc++.h>
using namespace std;

template<typename T> struct Node {
	
	// ------------------ DATA ---------------------------------

	private :
	
	T data ;
	Node * next ;

	// --------------------------------------------------------
	// --------------------- UTIL FUNCS  ----------------------

	public :

	// --------------- CONSTRUCTOR ----------------------------

	Node(T x){
		data = x ;
		next = NULL ;
	}

	// --------------------------------------------------------

	// --------------- SIZE OPS -------------------------------

	int size(Node * head){
		if(!head) return 0 ;
		return sizeUtil(head , 0) ;
	}
	int sizeUtil(Node * itr , int n){
		if(!itr) return n ;
		return sizeUtil(itr->next , n + 1) ;
	}

	// --------------------------------------------------------

	// --------------- SEARCH OPS -----------------------------

	int search(Node * head , T target){
		int p = 1 ; // 1 based indexing 
		while(head){
			if(head->data == target) return p ;
			++p ;
			head = head->next ;
		}
		return -1 ;
	}

	// --------------------------------------------------------

	// -------------- INSERT OPS ------------------------------

	Node * insertAtEnd(Node * head , T x){ 
		Node * newNode = new Node(x) ;
		if(!head) return newNode ;
		else{
			Node * i = head ;
			while(i->next) i = i->next ;
			i->next = newNode ;
		}
		return head ;
	}

	Node * insertAtBegigning(Node * head , T x){
		Node * newNode = new Node(x) ;
		newNode->next = head ;
		return newNode ;
	}

	Node * insertAtN(Node * head , T x , int pos){ // 1 based indexing 
		if(pos < 1){
			cout << "\nErr! Overflow condition for pos : " << pos << "\n" ;
			return head ;
		}
		if(pos == 1){
			return this->insertAtBegigning(head , x) ;
		}
		if(pos == this->size(this) + 1){
			return insertAtEnd(this , x) ; // size + 1 pos is to insert the element at the end of the newly created list
		}
		Node * itr = head ;
		// run the loop pos - 2 times to be at the index right before where we need to insert
		for(int i = 0 ; i < pos - 2 ; i++){
			 itr = itr->next ;
			// duting the process of iteration if the current position becomes greater than size + 1 then the overflow condiditon catches the error
			if(!itr){
				cout << "\nErr! Overflow condition for pos : " << pos << "\n" ;
				return head ;
			}
		}
		Node * newNode = new Node(x) ;
		newNode->next = itr->next ;
		itr->next = newNode ;
		return head ;
	}

	// --------------------------------------------------------

	// --------------- DELETE OPS -----------------------------

	Node * pop(Node * head){
		if(!head){
			cout << "head poitner is NULL\n" ;
			return NULL;
		}
		Node * temp = head->next ;
 		delete(head) ;
 		return temp ;
	}

	Node * pop_back(Node * head){
		if(!head || !head->next) return NULL;
		Node * itr = head ;
		while(itr->next->next) itr = itr->next ;
		Node * temp = itr->next ;
		itr->next = NULL ;
		delete(temp) ;
		return head ;
	}

	// --------------------------------------------------------


	// ------------------ PRINT OPS ---------------------------

	void printLL(Node * head){
		if(!head){
			cout <<"[]\n" ;
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

	void printNodes(Node * itr){ // this is a functuion that traverses through the ll in a recursive fashion
		if(!itr) return ; // this is the base condidition
		cout << itr->data << ", " ;
		this->printNodes(itr->next) ; // flex baby !
	}

	// --------------------------------------------------------
	// --------------------------------------------------------
	// --------------------------------------------------------


} ;

void Run() {
	// run your code here
	// There are three different ways to create an array in c++
	// 1. fixed size in the stack 
	int arr[5] ;
	// 2. in the heap 
	int * arrH = new int[5] ;
	// 3. as vectors of dynamic size 
	vector<int> arrV(5,-1) ;

	// Linked Lists : 
	Node<char> * head = new Node('a') ;
	for(char c = 'b' ; c <= 'g'; c++)
		head = head->insertAtBegigning(head , c) ;
	for(char c = 'b' ; c <= 'g'; c++)
		head = head->insertAtEnd(head , c) ;
	head->printLL(head) ;
	cout << "\npriting the nodes using recursion: \n" ;
	cout << "size: " << head->size(head) << "\n" ;
	head->printNodes(head) ;
	head = head->pop(head) ;
	head = head->pop(head) ;
	head = head->pop(head) ;
	cout << "\nafter removing some nodes from the start: \n" ;
	cout << "size: " << head->size(head) << "\n" ;
	head->printNodes(head) ;
	head = head->pop_back(head) ;
	head = head->pop_back(head) ;
	head = head->pop_back(head) ;
	cout << "\nafter removing some nodes from the back: \n" ;
	cout << "size: " << head->size(head) << "\n" ;
	head->printNodes(head) ;
	head = head->insertAtN(head , 'z' , head->size(head)) ; // size for insertion at the end of the old list
	head = head->insertAtN(head , 'z' , 1) ;
	head = head->insertAtN(head , 'z' , 890) ;
	head = head->insertAtN(head , 'z' , -1) ;
	head = head->insertAtN(head , 'z' , 4) ;
	head = head->insertAtN(head , 'x' , head->size(head) + 1) ; // size + 1 to insert at the end of the newly created list
	cout << "after inserting \'z\' at some places and \'x\' at the last place : \n" ;
	cout << "size: " << head->size(head) << "\n" ;
	head->printLL(head) ;
	int foundPos ;
	foundPos = head->search(head , 'a') ;
	foundPos == -1 ? cout << "\n\'a\' Not Found in the list\n" : cout << "\npos(first occurence) of \'a\' is : " << foundPos ;
	foundPos = head->search(head , 'g') ;
	foundPos == -1 ? cout << "\n\'g\' Not Found in the list\n" : cout << "\npos(first occurence) of \'g\' is : " << foundPos ;
	foundPos = head->search(head , 'z') ;
	foundPos == -1 ? cout << "\n\'z\' Not Found in the list\n" : cout << "\npos(first occurence) of \'z\' is : " << foundPos ;
	foundPos = head->search(head , 'x') ;
	foundPos == -1 ? cout << "\n\'x\' Not Found in the list\n" : cout << "\npos(first occurence) of \'x\' is : " << foundPos ;
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


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	Run();
    return 0;
}





