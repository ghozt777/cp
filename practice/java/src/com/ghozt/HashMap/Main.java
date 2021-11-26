package com.ghozt.HashMap;

import java.util.HashMap;
import java.util.Map ;

import static com.ghozt.OOP.L2.packages.HelloWorld.hello;

public class Main {
    public static void main(String[] args) {
        hello() ;
        HashMap<String , Integer> hm = new HashMap<>() ;
        hm.put("ghozt" , 7) ;
        hm.put("abc" , 123) ;
        hm.put("position" , 69) ;
        hm.put("u a whore" , 1) ;
        System.out.println("The contents of the map are");
        for(Map.Entry<String , Integer> e : hm.entrySet()){
            System.out.println(e.getKey() + " : " + e.getValue());
        }
        System.out.println(hm.size());
        // there is no particular order in which you get the result
        hm.remove("abc") ; // during the removal process the function returns the value corresponding to the key
        System.out.println(hm.containsKey("abc")) ;
        hm.remove("abc") ;
        System.out.println("after deletion the map is: ");
        for(Map.Entry<String , Integer> x : hm.entrySet()){
            System.out.println(x.getKey() + " : " + x.getValue());
        }
        // to get a value corresponding to a particular key use the get function:
        System.out.println(hm.get("position"));
        // if a key is not present then the get function will return null
        System.out.println(hm.get("test"));
        int arr[] = {10,12,10,15,10,20,12,12};
        printFrequency(arr);
    }
    static void printFrequency(int[] arr){
        HashMap<Integer , Integer> m = new HashMap<>() ;
//        for(int x : arr){
//            if(m.containsKey(x)){
//                m.put(x , m.get(x)+1);
//            }
//            else m.put(x,1);
//        }'
        // this is the shorthand expression for the above code :
        for(int x : arr) m.put(x , m.getOrDefault(x , 0) + 1) ;
        for(Map.Entry<Integer,Integer> x : m.entrySet()){
            System.out.println("value: " + x.getKey() + " freq: " + x.getValue()) ;
        }
    }
}
