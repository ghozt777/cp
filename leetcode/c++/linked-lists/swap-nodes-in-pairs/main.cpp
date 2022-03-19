// link : https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        int temp = head->val ;
        head->val = head->next->val ;
        head->next->val = temp ;
        ListNode * ptr = head->next->next ;
        while(ptr && ptr->next){
            int temp = ptr->val ;
            ptr->val = ptr->next->val ;
            ptr->next->val = temp ;
            ptr = ptr->next->next ;
        }
        return head ;
    }
};