#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int height(Node* head){
    if(!head) return 0;
    return 1 + height(head->next);
}


Node* bubbleSort(Node* head){
    if(!head) return head;
    int n = height(head);
    if(n == 1) return head;
    for(int i = 0; i < n; i++){
        Node* curr = head;
        Node* prev = NULL;
        while(curr && curr->next){
            if(curr->data > curr->next->data){
                if(!prev){
                    Node* temp = curr->next->next;
                    curr->next->next = curr;
                    head = curr->next;
                    curr->next = temp;
                    prev = head;
                } else{
                    Node* temp = curr->next->next;
                    prev->next = curr->next;
                    curr->next->next = curr;
                    curr->next = temp;
                    prev = prev->next;
                }
            } else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}



Node* takeinput()
{
    int data;
    cin >> data;
    Node* head = NULL, * tail = NULL;
    while(data != -1)
    {
        Node* newnode = new Node(data);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
        } else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node* head = takeinput();
    head = bubbleSort(head);
    print(head);
}