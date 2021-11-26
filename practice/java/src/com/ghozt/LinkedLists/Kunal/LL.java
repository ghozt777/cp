package com.ghozt.LinkedLists.Kunal;


public class LL {

    private Node head ;
    private Node tail ;
    private int size ;
    public LL(){
        this.size = 0 ;
    }

    public void insertAtBeginning(int data){
        Node newNode = new Node(data) ;
        newNode.next = head ;
        head = newNode ;
        if(tail == null) tail = head ;
        ++size ;
    }

    public void insertAtEnd(int data){
        Node newNode = new Node(data) ;
        if(tail == null){
            tail = newNode ;
            head = tail ;
        }
        else{
            tail.next = newNode ;
            tail = newNode ;
        }
        ++size ;
    }

    public void print(){
        Node itr = head ;
        while(itr!=null){
            System.out.print(itr.data + " -> ");
            itr = itr.next ;
        }
        System.out.print("END");
        System.out.println();
    }

    private class Node {
        private int data ;
        private Node next ;
        public Node(int data){
            this.data = data ;
            this.next = null ;
        }
    }
}
