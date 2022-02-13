#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Deque {
    // Complete this class
    Node* head;
    Node* tail;
    int size;
    int curr;

public:
    Deque(){
        head = NULL;
        tail = NULL;
        size = 0;
        curr = 0;
    }
    Deque(int size){
        head = NULL;
        tail = NULL;
        this->size = size;
        curr = 0;
    }
    void insertFront(int data){
        if(curr == size){
            cout << -1 << endl;
            return;
        }
        if(!head){
            head = new Node(data);
            tail = head;
        } else{
            Node* n = new Node(data);
            n->next = head;
            head = n;
        }
        ++curr;
        return;
    }
    void insertRear(int data){
        if(curr == size){
            cout << -1 << endl;
            return;
        }
        if(!head){
            head = new Node(data);
            tail = head;
        } else{
            Node* n = new Node(data);
            tail->next = n;
            tail = n;
        }
        ++curr;
    }
    void deleteFront(){
        if(curr == 0){
            cout << -1 << endl;
            return;
        }
        head = head->next;
        --curr;
        return;
    }
    void deleteRear(){
        if(curr == 0){
            cout << -1 << endl;
            return;
        }
        Node* curr = head;
        while(curr->next != tail) curr = curr->next;
        tail = curr;
        --curr;
        return;
    }
    int getFront(){
        if(curr == 0){
            return -1;
        }
        return head->data;
    }
    int getRear(){
        if(curr == 0){
            return -1;
        }
        return tail->data;
    }
};


// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice, input;
    while(true) {
        cin >> choice;
        switch(choice) {
        case 1:
        cin >> input;
        dq.insertFront(input);
        break;
        case 2:
        cin >> input;
        dq.insertRear(input);
        break;
        case 3:
        dq.deleteFront();
        break;
        case 4:
        dq.deleteRear();
        break;
        case 5:
        cout << dq.getFront() << "\n";
        break;
        case 6:
        cout << dq.getRear() << "\n";
        break;
        default:
        return 0;
        }
    }

    return 0;
}
