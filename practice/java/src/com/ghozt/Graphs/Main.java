package com.ghozt.Graphs;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        int v = 4 ;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(v) ;
        for(int i = 0 ; i < v ; i++) adj.add(new ArrayList<Integer>()) ;
        addEdge(adj , 0 , 1);
        addEdge(adj , 0 , 2);
        addEdge(adj , 1 , 2);
        addEdge(adj , 1 , 3);
        debug(adj);
    }
    static void addEdge(ArrayList<ArrayList<Integer>> adj , int u , int v){
        adj.get(u).add(v) ;
        adj.get(v).add(u) ;
    }
    static void debug(ArrayList<ArrayList<Integer>> adj){
        for(int i = 0 ; i < adj.size() ; i++){
            System.out.print(i + "th node is connected to: ");
            for(int j = 0 ; j < adj.get(i).size() ; j++){
                System.out.print(adj.get(i).get(j) + ", ");
            }
            System.out.println();
        }
    }
}
