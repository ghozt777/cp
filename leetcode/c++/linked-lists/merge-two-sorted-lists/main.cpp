// link : https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2 ;
        if(!l2) return l1 ;
        ListNode * head = NULL ;
        ListNode * curr = NULL ;
        while(l1 && l2){
            ListNode * toAdd = NULL ;
            if(l1->val <= l2->val) toAdd = l1 , l1 = l1->next ;
            else toAdd = l2 , l2 = l2->next ;
            if(!head) head = toAdd , curr = head ;
            else curr->next = toAdd , curr = curr->next ;
        }
        if(l1) curr->next = l1 ;
        if(l2) curr->next = l2 ;
        return head ;
    }
};