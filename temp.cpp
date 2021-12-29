#include<bits/stdc++.h>
using namespace std ;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode * insert(ListNode head , int x){
    if(!head){
        head = new ListNode(x) ;
        return head ;
    }
    ListNode * ptr = head ;
    while(ptr->next) ptr = ptr->next ;
    ptr->next = new ListNode(x) ;
    return head ;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode head = NULL ;
    int prevc = 0 ;
    int c = 0 ;
    while(l1 && l2){
        int s = (l1->x + l2->x + prevc) % 10 ;
        c = (s + prevc) / 10 ;
        prev = c ;
        head = insert(s) ;
        l1 = l1->next ;
        l2 = l2->next ;
    }
    while(l1){
        int s = (l1->x + prevc) % 10 ;
        c = (s + prevc) / 10 ;
        head = insert(s) ;
        l1 = l1->next ;
    }
    while(l2){
        int s = (l1->x + prevc) % 10 ;
        c = (s + prevc) / 10 ;
        prev = c ;
        head = insert(s) ;
        l2 = l2->next ;
    }
    return head ;
}

void printNodes(ListNode * head){
    while(head){
        cout << head->x << " " ;
        head = head->next ;
    }
}

int main(){
    ListNode head = new ListNode(12) ;
    printNodes(head) ;
    return 0 ;
}

