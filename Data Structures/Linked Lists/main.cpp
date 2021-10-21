#include<bits/stdc++.h>
using namespace std;

struct Node {
	pair<string , int> x;
	Node * next ; 
};

string getString(int);
Node* push_back(Node* , pair<string , int>);
Node* push_front(Node* , pair<string , int>);
Node* insert_node(Node* , pair<string , int> , int);
Node* delete_node(Node*, int);
Node* reverse_using_loop(Node*);
Node* reverse_using_recursion(Node*);
int node_size(Node*);
void Print(Node* , string);
void ReversePrint(Node* , string);
void helper(Node* , int);


void Run();

int main(){
	Run();
	return 0;
}
 
void Run() {

	Node * head = NULL;
	Node * head_two = NULL;

	for(int i = 0 ; i < 12 ; i++){
		head = push_front(head , make_pair(getString(i) + " 🍩" , i)); 
		if(i > 5) head_two = push_back(head_two , make_pair(getString(i) , i));
	}
	head_two = insert_node(head_two , make_pair(getString(69) , 69) , 1);
	head_two = insert_node(head_two , make_pair(getString(69) , 69) , 2);
	head_two = insert_node(head_two , make_pair(getString(69) , 69) , 5);
	// head_two = insert(head_two , make_pair(getString(69) , 69) , 69); this will throw an error
	Print(head , "\nprint the elements where elements are pushed back: \n");
	Print(head_two , "\nprint the elements where elements are pushed front: \n");
	cout << "\nThe size of the first Node is: \n" << node_size(head);
	cout << "\nThe size of the second Node is: \n" << node_size(head_two);	
	cout << "\n deleting the pos : 1 , 2 , 3 elements fron the second node we ge]]\t:\n";
	for(int i = 1  ; i <= 3 ; i++)
		head_two = delete_node(head_two , i);
	Print(head_two , "\nelements after deletion: \n");
	cout << "\nThe size after deletion: \n" << node_size(head_two);	
	head_two = reverse_using_loop(head_two);
	Print(head_two , "\n reversing the second node :\n"); 
	ReversePrint(head , "\nprinting the first node in reverse: \n");
	head = reverse_using_recursion(head);
	Print(head , "\n reversing the first node :\n");
}

Node* push_back(Node* head , pair<string , int> data){
	if(head == NULL){
		Node * newNode = new Node();
		newNode->x = data; 
		newNode->next = NULL;
		head = newNode; 
	}
	else {
		Node * ptr = head;
		while(ptr->next)
			ptr = ptr->next;
		Node * newNode = new Node();
		ptr->next = newNode;
		(*newNode).x = data;
		newNode->next = NULL;
	}
	return head;
}

Node* push_front(Node* head , pair<string , int> data){
	Node * newNode = new Node();
	newNode->x = data;
	newNode->next = head;
	head = newNode;
	return head;
}

void Print(Node* head, string message) {
	Node * ptr = head ;
	cout << message;
	int c = 0;
	while(ptr != NULL){
		cout << ++c <<"> 🧀 first: " << ptr->x.first << " || 🥨 second: " << ptr->x.second << "\n";
		ptr = ptr->next ; 
	}
}

void helper(Node * ptr , int count){
	if(!ptr) return;
	helper(ptr->next , count+1);
	cout << count <<"> 🧀 first: " << ptr->x.first << " || 🥨 second: " << ptr->x.second << "\n";
}

void ReversePrint(Node* head , string message) {
	cout << message ;
	helper(head , 1 );
}

int node_size(Node* ptr){
	int size = 0;
	while(ptr){
		++size;
		ptr = ptr->next;
	}
	return size;
}

Node * insert_node(Node * head , pair<string , int> data , int pos){
	if(pos > node_size(head) || pos < 1){
		throw runtime_error("out of bounds !");
	}

	if(pos == 1){
		Node * newNode = new Node();
		newNode->x = data;
		newNode->next = head;
		head = newNode ; 
		return head;
	}

	Node * ptr = head ;
	for(int i = 0 ; i < pos - 2 ; i++) // running the loop n - 2 times points to the n-1 node 
		ptr = ptr->next;
	Node * newNode = new Node();
	newNode->x = data;
	newNode->next = ptr->next;
	ptr->next = newNode ; 
	return head;
}

Node * delete_node(Node * head , int pos){
	if(pos > node_size(head) || pos < 1){
		throw runtime_error("out of bounds !");
	}

	if(pos == 1){
		Node* toDelete = head;
		head = head->next;
		delete(toDelete);
		return head;
	}
	Node * ptr = head ; 
	for(int i = 0 ; i < pos - 2 ; i++)
		ptr = ptr->next;
	Node * toDelete = ptr->next;
	ptr->next = toDelete->next;
	free(toDelete);
	return head; 
}

Node * reverse_using_loop(Node * head){
	  Node * curr , * prev , * next ;
	  prev = NULL;
	  curr = head;
	  while(curr){
	  	next = curr->next;
	  	curr->next = prev;
	  	prev = curr;
	  	curr = next;
	  }
	  return prev;
}

Node * reverse_using_recursion(Node * ptr){
	if(ptr ->next == NULL) return ptr;
	Node * head = reverse_using_recursion(ptr->next);
	Node * prev = ptr->next;
	prev->next = ptr;
	ptr->next = NULL;
	return head;
}

// utility functions: 

string getString(int val){
	switch(val){
		case 0:
			return "zero";
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		default :
			return "bigger than ur pp";

	}
}

