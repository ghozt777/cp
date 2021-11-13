#include<bits/stdc++.h>
using namespace std ;

struct Node {
	int data ;
	Node * next ;
	Node * prev ;
	Node(){
		data = 0 ;
		next = NULL ;
		prev = NULL ;
	}
	Node(int x){
		data = x ;
		next = NULL ;
		prev = NULL ;
	}

} ;

void printLL(Node *) ;
void printLLR(Node *) ;
Node * insertAtBegigning(Node * , int) ;
Node * insertAtEnd(Node * , int) ;
Node * reverse(Node *) ; 


void Run(){

	Node * head ;
	for(int i = 0 ; i < 4 ; i++) head = insertAtBegigning(head , i) ;
	for(int i = -1 ; i > - 4 ; i--) head = insertAtEnd(head , i) ;
	cout << "\n" ;
	printLL(head) ;
	cout << "\n" ;
	head = reverse(head) ;
	cout << "reversed LL(iterative) :\n" ;
	printLL(head) ;
}

Node * insertAtBegigning(Node * head , int x){
	Node * newNode = new Node(x) ;
	if(!head){
		return newNode ;
	}
	newNode->next = head ;
	head->prev = newNode ;
	return newNode ;
}

Node * insertAtEnd(Node * head , int x){
	if(!head) return insertAtBegigning(head,x) ;
	Node * itr = head ;
	while(itr->next) itr = itr->next ;
	Node * newNode = new Node(x) ;
	newNode->prev = itr ;
	itr->next = newNode ;
	return head ;
}

void printLL(Node * itr){
	if(!itr) return ; 
	cout << itr->data << ", " ;
	printLL(itr->next) ;
}

void printLLR(Node * itr){
	if(!itr) return ;
	printLLR(itr->next) ;
	cout << itr->data << ", " ;
}

Node * reverse(Node * head){
	// In a doubly LL we just flip the next and the prev pointers and update the head to reverse it
	if(!head || !head->next) return head ;
	Node * itr = head ;
	while(itr){
		if(!itr->next) head = itr ;
		Node * temp ;
		temp = itr->next ;
		itr->next = itr->prev ;
		itr->prev = temp ;
		itr = temp;
	}
	return head ;
}

int main(){
	Run() ;
	return 0 ;
}