#include <bits/stdc++.h>

class Node
{
public:
    Node *next;
    int data;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

Node *midpoint(Node *head)
{
    if (!head)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    std::cout << "The mid value is : ";
    std::cout << midpoint(head)->data << " " << std::endl;
    return 0;
}