package com.ghozt.DP;

import java.util.HashMap;
import java.util.Scanner;

public class Fib {

// question : write a function `fib(n)` that takes a number `n` as an argument and returns the n-th number
// from the fibonacci series

// YT : https://www.youtube.com/watch?v=oBt53YbR9Kk

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter n : ");
        int n = in.nextInt();
        System.out.print("The " + n + "th Fibonacci Number is : " + fib(n));
    }


    // memoized fibonacci function :

    public static int fib(int n) {
        HashMap<Integer, Integer> memo = new HashMap<>();
        return fibUtil(n, memo);
    }

    public static int fibUtil(int n, HashMap<Integer, Integer> memo) {
        if (memo.containsKey(n)) return memo.get(n);
        if (n <= 2) return 1;
        memo.put(n, fibUtil(n - 1, memo) + fibUtil(n - 2, memo));
        return memo.get(n);
    }


}