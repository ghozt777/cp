// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        vector<int> arr ;
        while(head) arr.push_back(head->val) , head = head->next ;
        int start = 0 ;
        int end = arr.size() - 1 ;
        while(start < end){
            if(arr[start] != arr[end]) return false ;
            ++start ;
            --end ;
        }
        return true ;
    }
};