package com.ghozt.Leetcode.AddTwoNumbers;

public class Main {

    static class ListNode {
        int val;
        ListNode next ;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public static void main(String[] args) {
        ListNode l1 = convertToList(9999999991L) ;
        ListNode l2 = convertToList(9) ;
        printList(addTwoNumbers(l2,l1));
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        long sum = getVal(l1) + getVal(l2) ;
        return convertToList(sum) ;
    }

    public static ListNode convertToList(long n){
        long r = n%10L ;
        ListNode head = new ListNode((int)r) ;
        n /= 10 ;
        ListNode ptr = head ;
        while(n != 0){
            r = n%10L ;
            ptr.next = new ListNode((int)r) ;
            ptr = ptr.next ;
            n /= 10 ;
        }
        return head ;
    }

    public static long getVal(ListNode head){
       if(head == null) return 0;
       return getVal(head.next)* 10 + head.val ;
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
