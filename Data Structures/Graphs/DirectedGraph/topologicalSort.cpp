/*
    TOPOLOGICAL SORT : SORTING BASED ON DEPEDENCY -> MAY NOT BE UNIQUE
    NOT POSSIBLE FOR UNDIRECTED OR CYCLIC GRAPHS 
    OLNY POSSIBLE FOR DAGs (DIRECETD ACYCLIC GRAPHs)

    APPLICATION : COMPILING DEPENDECY GRAPH IN MODULES WHERE THE MODULES WHICH ARE DEPENDENT ON OTHER MODULES ARE COMPILER LATER THAN THE ONES THAT THEY DEPEND ON , etc

    GFG : https://www.geeksforgeeks.org/topological-sorting/
*/


#include<bits/stdc++.h>
#include "./DirectedGraph.h"
using namespace std ;

int main(){

    DirectedGraph g(5) ;
    g.addEdge(0,2) ;
    g.addEdge(0,3) ;    
    g.addEdge(2,3) ;
    g.addEdge(1,3) ;
    g.addEdge(1,4) ;


    for(int x : g.topologicalSort()) cout << x << " " ;
    cout << endl ;

    return 0 ;
}