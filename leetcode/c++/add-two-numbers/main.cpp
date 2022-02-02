// link : https://leetcode.com/problems/add-two-numbers/
#include<bits/stdc++.h>
using namespace std ;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode * insert(ListNode * head , int x){
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
    ListNode * head = NULL ;
    int c = 0 ;
    int s = 0 ;
    while(l1 || l2 || c != 0){
        if(l1 && l2){ s = (l1->val + l2->val + c) ; l1 = l1->next ; l2 = l2->next ;}
        else if(l1 && !l2){ s = (l1->val + c) ; l1 = l1->next ;}
        else if(!l1 && l2){ s = (l2->val + c) ; l2 = l2->next ;}
        else s = c ;
        c = s / 10 ;
        head = insert(head , s % 10) ;
    }
    return head ;
}

void printNodes(ListNode * head){
    while(head){
        cout << head->val << " " ;
        head = head->next ;
    }
}

int main(){
    ListNode * l1 = new ListNode(9) ;
    l1 = insert(l1 , 9) ;
    l1 = insert(l1 , 9) ;
    l1 = insert(l1 , 9) ;
    l1 = insert(l1 , 9) ;
    l1 = insert(l1 , 9) ;
    l1 = insert(l1 , 9) ;
    ListNode * l2 = new ListNode(9) ;
    l2 = insert(l2 , 9) ;
    l2 = insert(l2 , 9) ;
    l2 = insert(l2 , 9) ;
    ListNode * ans = addTwoNumbers(l1, l2) ;
    printNodes(ans) ;
    delete l1 ;
    delete l2 ;
    delete ans ;
    return 0 ;
}
