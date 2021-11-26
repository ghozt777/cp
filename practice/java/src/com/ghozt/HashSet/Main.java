package com.ghozt.HashSet;
import java.util.HashSet ;
import java.util.Iterator ;
public class Main {
    public static void main(String[] args) {
        HashSet<String> hs = new HashSet<>(5) ;
        hs.add("ghozt") ;
        hs.add("cunt") ;
        hs.add("hoe") ;
        System.out.println(hs);
        System.out.println(hs.contains("ghozt"));
        System.out.println(hs.contains("abc"));
        Iterator<String> i = hs.iterator() ;
        while(i.hasNext()){
            System.out.print(i.next() + " ");
        }
        // also the ad function add an item if the item is not present and return true and if the item is already present it ignores the element and then returns false .
        hs.remove("ghozt")  ; // if the item is remove it returns true else returns false
        System.out.println();
        System.out.println(hs.isEmpty());
        hs.clear() ;
        System.out.println(hs.isEmpty());
        // Time Complexities:
        // O(1) for add() remove() and contains()
        // O(1) for isEmpty() size()

    }
}
