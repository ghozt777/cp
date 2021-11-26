package com.ghozt.HashSet;

import java.util.HashSet;
import java.util.Arrays ;

public class CountDistinctElements {
    public static void main(String[] args) {
        int[] arr = {15,12,13,12,13,13,18} ;
        System.out.print("In array : " + Arrays.toString(arr) + " ");
        distinctCount(arr);
        Integer[] arrInt = {15,12,13,12,13,13,1} ;
        distinctCountEfficient(arrInt);
        System.out.println("Using Brute force: ");
        bruteforce(arr);
        arr = new int[] {10,10,10,10,10,10,10,10} ;
        arrInt = new Integer[]{10,10,10,10,10,10,10,10} ;
        System.out.print("In array : " + Arrays.toString(arr) + " ");
        distinctCount(arr);
        distinctCountEfficient(arrInt);
        System.out.println("Using Brute force: ");
        bruteforce(arr);
    }
    static void distinctCount(int[] arr){
        HashSet<Integer> unique = new HashSet<>() ;
        for(int x : arr) unique.add(x) ;
        System.out.println("Number of unique elements are = " + unique.size());
    }
    static void bruteforce(int[] arr){
        int count = 0 ;
        for(int i = 0 ; i < arr.length ; i++){
            boolean isThere = false ;
            for(int j = i - 1 ; j >=0 ; j--){
                if(arr[j] == arr[i]){
                    isThere = true ;
                    break ;
                }
            }
            if(!isThere) ++count ;
        }
        System.out.println("Number of unique elements = " + count);
    }

    static void distinctCountEfficient(Integer[] arr){
        HashSet<Integer> unique = new HashSet<>(Arrays.asList(arr)) ;
        System.out.println("Number of unique elements = " + unique.size());
    }

}
