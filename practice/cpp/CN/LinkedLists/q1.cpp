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
#include<bits/stdc++.h>
#include <iostream>
using namespace std;


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



vector<int> convert(Node * head){
    Node * curr = head ;
    vector<int> arr ;
    while(curr){
        arr.push_back(curr->data) ;
        curr = curr->next ;
    }
    return arr ;
}

Node * convert(vector<int> &arr){
    Node * head = NULL ;
    Node * curr = head ; 
    for(int x : arr){
        if(!head){
            head = new Node(x) ;
        }
        else {
            curr->next = new Node(x) ;
            curr = curr->next ;
        }
    }
    return head ;
}

void merge(vector<int> &arr , int start , int mid , int end){
    int i = start ;
    int j = mid + 1 ;
    int k = start ;
	int buffer[100] ;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){ buffer[k++] = arr[i] ; i++ ;}
        else {buffer[k++] = arr[j] ; j++ ;}
    }
    while(i <= mid){ buffer[k++] = arr[i] ; i++ ;}
    while(j <= end){buffer[k++] = arr[j] ; j++ ;}
    for(int x = start ; x <= end ; x++) arr[x] = buffer[x] ;
    return ;
}


void mergeSortUtil(vector<int> &arr ,int start , int end){
    if(start > end) return ;
    int mid = start + (end - start) / 2 ;
    mergeSortUtil(arr , start , mid) ;
    mergeSortUtil(arr , mid + 1, end) ;
    merge(arr , start , mid , end) ;
}


Node *mergeSort(Node *head)
{
	//Write your code here
    vector<int> arr = convert(head) ;
    mergeSortUtil(arr , 0 , arr.size() - 1) ;
	head = convert(arr) ;
    return head ;
}

// -- Driver code : 







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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}



