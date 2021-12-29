package com.ghozt.MergeTwoSortedLists;

// link: https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */



public class Main {

    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public static void main(String[] args) {
        ListNode head1 = null ;
        ListNode head2 = null ;
        head1 = new ListNode(1) ;
//        head1.next = new ListNode(2) ;
//        head1.next.next = new ListNode(4);
        head2 = new ListNode(1) ;
        head2.next = new ListNode(3) ;
        head2.next.next = new ListNode(4) ;
        ListNode head = mergeTwoLists(head1 , null) ;
        printList(head);
    }

    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null && list2 == null) return null ;
        ListNode head  = null ;

        ListNode ptr1 = list1 ;
        ListNode ptr2 = list2 ;
        if(ptr1 != null && ptr2 == null){
            head = ptr1 ;
            ptr1 = ptr1.next ;
        }
        else if (ptr2 != null && ptr1 == null){
            head = ptr2 ;
            ptr2 = ptr2.next ;
        }
        else if(ptr1.val <= ptr2.val ) {
            head = ptr1 ;
            ptr1 = ptr1.next ;
        }
        else {
            head = ptr2 ;
            ptr2 = ptr2.next ;
        }
        ListNode ptr = head ;
        while(ptr1 != null && ptr2 != null){
            ListNode newNode = null ;
            if(ptr1.val <= ptr2.val){
                newNode = new ListNode(ptr1.val , ptr1.next) ;
                ptr1 = ptr1.next ;
            }
            else {
                newNode = new ListNode(ptr2.val , ptr2.next) ;
                ptr2 = ptr2.next ;
            }
            ptr.next = newNode ;
            ptr = ptr.next ;
        }

        while(ptr1 != null){
            ListNode newNode = new ListNode(ptr1.val , ptr1.next) ;
            ptr1 = ptr1.next ;
            ptr.next = newNode ;
            ptr = ptr.next ;
        }

        while(ptr2 != null){
            ListNode newNode = new ListNode(ptr2.val , ptr2.next) ;
            ptr2 = ptr2.next ;
            ptr.next = newNode ;
            ptr = ptr.next ;
        }

        return head ;
    }

    public static ListNode insertNode(ListNode head , int val){
        if(head == null){
            ListNode newHead = new ListNode(val) ;
            return newHead ;
        }
        head.next = new ListNode(val) ;
        return head ;
    }

    public static void printList(ListNode head){
        if(head == null){
            System.out.println("[]");
            return ;
        }
        if(head.next == null){
            System.out.println("[" + head.val + "]");
            return ;
        }
        System.out.print("[");
        System.out.print(head.val + ", ");
        head = head.next ;
        while(head.next != null){
            System.out.print(head.val + ", ");
            head = head.next ;
        }
        System.out.print(head.val + "]");
        System.out.println();
    }
}