// link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    int height(ListNode * head){
        int n = 0 ;
        while(head) ++n , head = head->next ;
        return n ;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(!head || !head->next) return NULL ;
        int n = height(head) ;
        if(n == k){
            head = head->next ;
            return head ;
        }
        ListNode * curr = head ;
        for(int i = 0 ; i < n - k - 1 ; i++) curr = curr->next ;
        if(k != n) curr->next = curr->next->next ;
        else curr->next = NULL ;
        return head;
    }
};

