#include <unordered_set>
#include <iostream>

using namespace std;

class Node
{
    int val;
    Node *next;

public:
    Node()
    {
        this->val = 0;
        this->next = NULL;
    }

    Node(int val)
    {
        Node();
        this->val = val;
    }

    Node(int val, Node *next)
    {
        Node();
        this->val = val;
        this->next = next;
    }

    Node *insert(Node *head, int val)
    {
        if (!head)
        {
            head = new Node(10);
            return head;
        }

        Node *newNode = new Node(val, head);
        return newNode;
    }

    void printNodes(Node *head)
    {
        if(!head) return ;
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main()
{
    unordered_set<int> s;

    for (int i = 0; i < 10; i++)
        s.insert(i + 1);
    for (int x : s)
        cout << x << " "; // there is no particular order in which the elements are stored
    cout << endl;

    // using iterators :
    for (unordered_set<int>::iterator x = s.begin(); x != s.end(); x++)
        cout << *x << " ";

    // to get the size :
    cout << "size: " << s.size();
    cout << endl;

    cout << endl;

    Node *head = new Node();

    for (int i = 10; i < 20; i++)
        head = head->insert(head, i + 1);

    head->printNodes(head);

    unordered_set<Node*> sNode ;
    for(int i = 0 ; i < 10 ; i++){
        sNode.insert(new Node(i*5)) ;
    }

    for(auto x : sNode) x->printNodes(x);

    cout << endl;

    return 0;
}