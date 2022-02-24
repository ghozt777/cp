#include<bits/stdc++.h>
#include "./DirectedGraph.h"

using namespace std ;

int main(){
    // dosen't contain cycle
    DirectedGraph g1(3) ;
    g1.addEdge(0,1) ;
    g1.addEdge(1,2) ;
    g1.detectCycle() ? cout << "graph1 has cycle " << endl : cout << "graph1 dosen't have a cycle" << endl;
    g1.detectCycleKakns() ? cout << "graph1 has cycle " << endl : cout << "graph1 dosen't have a cycle" << endl;

    cout << endl ;

    // contains cycle
    DirectedGraph g2(6) ;
    g2.addEdge(0 , 1) ;
    g2.addEdge(2 , 1) ;
    g2.addEdge(2 , 3) ;
    g2.addEdge(3 , 4) ;
    g2.addEdge(4 , 5) ;
    g2.addEdge(5 , 3) ;
    g2.detectCycle() ? cout << "graph2 has cycle " << endl : cout << "graph2 dosen't have a cycle" << endl;
    g2.detectCycleKakns() ? cout << "graph2 has cycle " << endl : cout << "graph2 dosen't have a cycle" << endl;

    cout << endl ;

    // contains cycle 
    DirectedGraph g3(4) ;
    g3.addEdge(0 , 1) ;
    g3.addEdge(1 , 2) ;
    g3.addEdge(2 , 3) ;
    g3.addEdge(3 , 1) ;
    g3.detectCycle() ? cout << "graph3 has cycle " << endl : cout << "graph3 dosen't have a cycle" << endl;
    g3.detectCycleKakns() ? cout << "graph3 has cycle " << endl : cout << "graph3 dosen't have a cycle" << endl;

    cout << endl ;

    // dosen't contain cycle
    DirectedGraph g4(4) ;
    g4.addEdge(0 , 1) ;
    g4.addEdge(2 , 1) ;
    g4.addEdge(2 , 3) ;
    g4.addEdge(1 , 3) ;
    g4.detectCycle() ? cout << "graph4 has cycle " << endl : cout << "graph4 dosen't have a cycle" << endl;
    g4.detectCycleKakns() ? cout << "graph4 has cycle " << endl : cout << "graph4 dosen't have a cycle" << endl;

    return 0 ;
}