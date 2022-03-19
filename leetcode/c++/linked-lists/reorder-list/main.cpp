// link : https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        vector<int> buff ;
        ListNode * ptr = head ;
        while(ptr){
            buff.emplace_back(ptr->val) ;
            ptr = ptr->next ;
        }
        int start = 0 ;
        int end = buff.size() - 1 ;
        int curr = 0 ;
        ptr = head ;
        while(ptr && start <= end){
            if(curr %2 == 0) ptr->val = buff[start++];
            else ptr->val = buff[end--] ;
            ptr = ptr->next ;
            ++curr ;
        }
    }
};