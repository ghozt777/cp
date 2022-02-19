// link : https://leetcode.com/problems/sort-list/

// uses merge sort

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
  ListNode * mergeTwoSortedLinkedLists(ListNode * head1, ListNode * head2) {
    //Write your code here
    if (!head1 && !head2) return NULL;
    if (!head1) return head2;
    if (!head2) return head1;
    ListNode * head = NULL;
    ListNode * curr = NULL;
    ListNode * i = head1;
    ListNode * j = head2;
    if (i -> val <= j -> val) {
      head = i;
      curr = i;
      i = i -> next;
    } else {
      head = j;
      curr = j;
      j = j -> next;
    }
    while (i && j) {
      if (i -> val <= j -> val) {
        curr -> next = i;
        i = i -> next;
      } else {
        curr -> next = j;
        j = j -> next;
      }
      curr = curr -> next;
    }
    if (i) curr -> next = i;
    if (j) curr -> next = j;
    return head;
  }

  ListNode * getMidNode(ListNode * head) {
    if (!head) return NULL;
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast && fast -> next && fast -> next -> next) {
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    return slow;
  }

  ListNode * util(ListNode * head) {
    if (!head || !head -> next) return head;
    ListNode * mid = getMidNode(head);
    ListNode * l = mid -> next;
    mid -> next = NULL;
    ListNode * h1 = util(head);
    ListNode * h2 = util(l);
    return mergeTwoSortedLinkedLists(h1, h2);
  }

  ListNode * mergeSort(ListNode * head) {
    //Write your code here
    return util(head);
  }
  public:
    ListNode * sortList(ListNode * head) {
      return mergeSort(head);
    }
};