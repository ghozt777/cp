// link : https://leetcode.com/problems/odd-even-linked-list/

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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        vector<int> odd;
        vector<int> even;
        ListNode *ptr = head;
        int c = 1;
        while (ptr)
        {
            if (c % 2 == 0)
                even.push_back(ptr->val);
            else
                odd.push_back(ptr->val);
            ptr = ptr->next;
            ++c;
        }
        ptr = head;
        c = 0;
        while (ptr && c < odd.size())
            ptr->val = odd[c++], ptr = ptr->next;
        c = 0;
        while (ptr && c < even.size())
            ptr->val = even[c++], ptr = ptr->next;
        return head;
    }
};