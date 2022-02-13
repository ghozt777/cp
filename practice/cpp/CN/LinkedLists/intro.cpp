#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
using namespace std;



/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node * g_head = NULL ;
int curr = 0 ;

void util(Node * head){
		if(!head) return ;
    util(head->next) ;
    if(curr > 0){
        --curr ;
        Node * h = new Node(head->data) ;
        h->next = g_head ;
        g_head = h ;
		}
    else return ;
    return ;
}

void del(Node * head , int c){
		int n = 0 ;
		Node * i = head ;
		while(i){++n ; i = i->next ;}
		Node * curr = head ;
		for(int i = 0 ; i < n - c - 1 ; i++) curr = curr->next ;
		for(int i = 0 ; i < c ; i++){
				Node * temp = curr->next ;
				curr->next = NULL ;
				curr = temp ;
		}
}

Node *appendLastNToFirst(Node *head, int pos)
{
    //Write your code here
    if(!head || pos == 0) return head ;
    g_head = head ;
    curr = pos ;
    util(head) ;
    del(head , pos) ;
    return g_head ;
}


// --------------------




Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
