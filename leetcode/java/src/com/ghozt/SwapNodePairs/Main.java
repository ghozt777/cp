package com.ghozt.SwapNodePairs;

// link : https://leetcode.com/problems/swap-nodes-in-pairs/
public class Main {

    static class ListNode {
        int val ;
        ListNode next ;
        ListNode(int val){
            this.val = val ;
            this.next = null ;
        }
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1) ;
        head.next = new ListNode(2) ;
        head.next.next = new ListNode(3) ;
        head.next.next.next = new ListNode(4) ;
        head = swapPairs(head) ;
        ListNode itr = head ;
        while(itr != null) {
            System.out.print(itr.val + " ");
            itr = itr.next ;
        }
    }

    static public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode first=head;
        ListNode second=head.next;
        ListNode remainingNode=swapPairs(head.next.next);
        first.next=remainingNode;
        second.next=first;
        return second;
    }

}