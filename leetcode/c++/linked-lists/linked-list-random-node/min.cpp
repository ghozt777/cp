// link : https://leetcode.com/problems/linked-list-random-node/

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
    int size ;
    ListNode * head ;
public:
    Solution(ListNode* head) {
        this->head = head ;
        ListNode * ptr = head ;
        int c = 0 ;
        while(ptr) ++c , ptr = ptr->next ;
        this->size = c ;
    }
    
    int getRandom() {
        if(size == 1) return this->head->val ;
        int randomIndex = rand() % size + 0 ;
        int curr = 0 ;
        ListNode * ptr = this->head ;
        while(ptr && curr <= this->size && curr != randomIndex) ++curr , ptr = ptr->next ;
        return ptr->val ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */