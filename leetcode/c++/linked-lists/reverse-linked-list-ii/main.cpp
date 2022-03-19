// link : https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head ;
        vector<int> buff ;
        ListNode * ptr = head ;
        int curr = 1 ;
        while(ptr){
            if(curr >= left && curr <= right) buff.emplace_back(ptr->val) ;
            if(curr > right) break ;
            ptr = ptr->next ;
            ++curr ;
        }
        ptr = head ;
        curr = 1 ;
        int i = buff.size() - 1 ;
        while(ptr){
            if(curr >= left && curr <= right) ptr->val = buff[i--] ;
            if(curr > right) break ;
            ptr = ptr->next ;
            ++curr ;
        }
        return head ;
    }
};