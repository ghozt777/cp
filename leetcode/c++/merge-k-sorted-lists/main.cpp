// link : https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> data ;
        for(ListNode * head : lists) while(head) data.emplace_back(head->val) , head = head->next ;
        sort(data.begin() , data.end()) ;
        ListNode * head = NULL ;
        ListNode * curr = NULL ;
        for(int x : data){
            if(!head) head = new ListNode(x) , curr = head ;
            else curr->next = new ListNode(x) , curr = curr->next ;
        }
        return head ;
    }
};