// link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s ;
        ListNode * ptr = head ;
        while(ptr){
            s.insert(ptr->val) ;
            ptr = ptr->next ;
        }
        ListNode * newHead = NULL ;
        ptr = newHead ;
        for(int x : s){
            if(!newHead){
                newHead = new ListNode(x) ;
                ptr = newHead ;
            }
            else{
                ptr->next = new ListNode(x) ;
                ptr = ptr->next ;
            }
        }
        return newHead ;
    }
};