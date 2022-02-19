//  link : https://leetcode.com/problems/copy-list-with-random-pointer/

/*
 IDEA : First create a hash map full of new Nodes
        Then create connections within existing nodes
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node * , Node *> elems ; // <old , new>
        Node * curr = head ;
        while(curr) elems[curr] = new Node(curr->val) , curr = curr->next ;
        curr = head ;
        while(curr) elems[curr]->next = elems[curr->next] , elems[curr]->random = elems[curr->random] , curr = curr->next ;
        return elems[head] ;
    }
};