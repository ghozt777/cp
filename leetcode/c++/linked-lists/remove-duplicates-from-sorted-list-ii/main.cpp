// link : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        map<int , int> m ;
        ListNode * ptr = head ;
        while(ptr){
            ++m[ptr->val] ;
            ptr = ptr->next ;
        }
        ListNode * newHead = NULL ;
        ptr = newHead ;
        for(pair<int  , int> x : m){
            if(x.second < 2){
                if(!newHead){
                    newHead = new ListNode(x.first) ;
                    ptr = newHead ;
                }
                else{
                    ptr->next = new ListNode(x.first) ;
                    ptr = ptr->next ;
                }
            }
        }
        return newHead ;
    }
};