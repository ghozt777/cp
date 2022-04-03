package com.ghozt.codeforces;

import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        int t ;
        Scanner in = new Scanner(System.in);
        t = in.nextInt() ;
        for(int tc = 0 ; tc < t ; tc++) runTestCase() ;
    }
    static void runTestCase(){
        int n ;
        Scanner in =  new Scanner(System.in) ;
        n = in.nextInt() ;
        int[] arr = new int[n] ;
        for(int i = 0 ; i < n ; i++) arr[i] = in.nextInt() ;
        if(n == 1){
            System.out.println(arr[0] == 1 ? "YES" : "NO") ;
            return ;
        }
        Arrays.sort(arr) ;
        System.out.println(arr[n - 1] - arr[n - 2] > 1 ? "NO" : "YES");
    }
}
