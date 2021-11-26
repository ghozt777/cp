package com.ghozt.LinkedLists.Kunal;

public class Main {
    public static void main(String[] args) {
        LL list = new LL() ;
        for(int i = 0 ; i < 10 ; i++) list.insertAtBeginning(i);
        list.print();
        for(int i = 0 ; i < 10 ; i++) list.insertAtEnd(i);
        list.print() ;
    }
}
