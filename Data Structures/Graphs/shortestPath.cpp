#include<bits/stdc++.h>
#include "./UndirectedGraph.h"
using namespace std ;


int main(){ 
    UndirectedGraph g1(4) ;
    g1.addEdge(0,1) ;
    g1.addEdge(0,2) ;
    g1.addEdge(1,3) ;
    g1.addEdge(1,2) ;
    g1.addEdge(2,3) ;
    g1.shortestPath() ;
    g1.shortestPath(0) ;
    return 0 ;
}