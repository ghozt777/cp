// link : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode * util(ListNode * head , ListNode * tail){
        if(head == tail) return NULL ;
        if(!head->next) return new TreeNode(head->val) ;
        ListNode * slow = head ;
        ListNode * fast = head ;
        while(fast != tail && fast->next != tail){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        TreeNode * root = new TreeNode(slow->val) ;
        root->left = util(head , slow) ;
        root->right = util(slow->next , tail) ;
        return root ;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL ;
        return util(head , NULL) ;
    }
};