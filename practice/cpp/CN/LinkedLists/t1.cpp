#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node* reverse(Node* head){
    if(!head->next || !head) return head;
    Node* h = reverse(head->next);
    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return h;
}

Node* NextLargeNumber(Node* head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    head = reverse(head);
    Node* curr = head;
    if(curr->data < 9){
        curr->data += 1;
        return reverse(head);
    }
    curr->data = 0;
    curr = curr->next;
    int carry = 1;
    Node* last = curr;
    while(curr && carry != 0){
        int sum = curr->data + carry;
        carry = sum / 10;
        sum %= 10;
        curr->data = sum;
        if(!curr->next) last = curr;
        curr = curr->next;
    }
    if(carry != 0) last->next = new Node(carry);
    return reverse(head);
}




using namespace std;

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, * tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = takeinput();

    head = NextLargeNumber(head);
    print(head);
    return 0;
}



