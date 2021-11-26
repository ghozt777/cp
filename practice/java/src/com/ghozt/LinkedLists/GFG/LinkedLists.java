package com.ghozt.LinkedLists.GFG;
import java.util.ArrayList ;


final class Node { // self-referential structure
    int data ;
    Node next ; // has reference of self type
    Node(int x){
        data = x ;
        next = null ;
    }
}

public class LinkedLists {
    public static void main(String[] args) {
        // Arrays :
        int[] arr  = {1,2,3,4} ;
        // similar to vectors in c++
        ArrayList<Integer> arrL = new ArrayList<>(5) ;
        // Linked List :
        Node head = null ;
        for(int i = 0 ; i < 10 ; i++) head = pb(head ,i) ;
        System.out.println("\nIterative traversal: ");
        printNodes(head);
        System.out.println("\nrecursive traversal: ");
        printNodesRecursively(head);
        head = pop(head) ;
        head = pop(head) ;
        head = pop_back(head) ;
        head = pop_back(head) ;
        System.out.println("\nAfter deleting a couple of nodes:");
        printNodes(head);
        System.out.println("Adding some elements at random position: ");
        head = insertAtN(head , -1 , 1) ;
        head = insertAtN(head , -69 , 12) ;
        head = insertAtN(head , 67 , size(head) + 1) ; // size + 1 to insert at the end of the newly created list not the old one
        head = insertAtN(head , 23 , -99) ;
        head = insertAtN(head , 999 , 4) ;
        printNodes(head);
        System.out.println();
        System.out.println("position of -10 in the list is : " + search(head , -10));
        System.out.println("position of 67 in the list is : " + search(head , 67));
        System.out.println("position of 5 in the list is : " + search(head , 5));
    }
    static Node pb(Node head , int x){
        if(head == null){
            Node newNode = new Node(x) ;
            newNode.next = head ;
            head = newNode ;
            return head ;
        }
        else {
            Node i = head ;
            while(i.next != null) i = i.next ;
            Node newNode = new Node(x) ;
            i.next = newNode ;
            return head ;
        }
    }

    static void printNodes(Node head){
        while(head != null){
            System.out.print(head.data + ", ");
            head = head.next ;
        }
    }

    static void printNodesRecursively(Node itr){
        if(itr == null) return ; // this is the base condition
        System.out.print(itr.data + ", ");
        printNodesRecursively(itr.next);
    }

    static Node pop(Node head){
        if(head == null){
            System.out.println("Can't delete Head pointer is null\n");
            return null ;
        }
        return head.next ;
    }

    static Node pop_back(Node head){
        if(head == null || head.next == null) return null ;
        Node itr = head ;
        while(itr.next.next != null) itr = itr.next ;
        itr.next = null ;
        return head;
    }

    static Node insertAtN(Node head , int x , int pos){
        if(head == null){
            System.out.println("\nhead is null") ;
            return null ;
        }
        if(pos > size(head) + 1 || pos < 1){
            System.out.println("\nErr! Overflow condition for pos : " + pos) ;
            return head ;
        }
        if(pos == 1){
            return insertAtBegigning(head , x) ;
        }
        if(pos == size(head) + 1){
            return pb(head , x) ;
        }
        System.out.println("POS: " + pos);
        Node itr = head ;
        int c = 0 ;
        // run the loop pos - 2 times to be at the index right before where we need to insert
        for(int i = 0 ; i < pos - 2 ; i++){
            itr = itr.next ;
            ++c ;
        }
        System.out.println("Loop Rum Count: " + c + " cure eleme : " + itr.data);
        Node newNode = new Node(x) ;
        newNode.next = itr.next ;
        itr.next = newNode ;
        return head ;
    }

    static Node insertAtBegigning(Node head , int x){
        Node newNode = new Node(x) ;
        newNode.next = head ;
        return newNode ;
    }

    static int size(Node head){
        int c = 0 ;
        while(head != null){
            ++c ;
            head = head.next ;
        }
        return c ;
    }

    static int search(Node head , int target){
        int p = 1 ; // 1 based indexing
        while(head != null){
            if(head.data == target) return p ;
            ++p ;
            head = head.next ;
        }
        return -1 ;
    }

}
/*
	Notes :

	Problems associated with array data structure :
	Arrays store all of its elements as a contagious memory block whereas a Linked Lists stores its elements in random order
	Arrays and Lined Lists are the biggest competitors of each other

	Now the potential problems with arrays :
	1. We need to preallocate the space
	2. The problem with vectors is that during insertion if its reaches its size then it needs to create a new array with double its size and then copy all its elements to the newly created one which takes O(n)
	Therefore in some cases it may take O(n) time for insertion(for vectors).
	3. Insertion / Deletion in the middle is costly
	4. Implementation of Data Structures like Queue and Deque is complex using arrays

*/
