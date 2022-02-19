// link : https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> seen ;
        ListNode * curr = headA ;
        while(curr){
            seen.insert(curr) ;
            curr = curr->next ;
        }
        curr = headB ;
        while(curr){
            if(seen.find(curr) != seen.end()) return curr ;
            curr = curr->next ;
        }
        return NULL ;
    }
};