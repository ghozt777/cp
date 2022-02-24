#include<bits/stdc++.h>
#include "./UndirectedGraph.h"
using namespace std;

int main() {
    UndirectedGraph g1(6);
    g1.addEdge(1, 0);
    g1.addEdge(2, 3);
    g1.addEdge(4, 5);

    UndirectedGraph g2(6);
    g2.addEdge(1, 0);
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 3);
    g2.addEdge(2, 4);
    g2.addEdge(4, 5);


    g1.detectCycle() ? cout << "graph1 has cycle " << endl : cout << "graph1 dosen't have a cycle" << endl;
    g2.detectCycle() ? cout << "graph2 has cycle " << endl : cout << "graph2 dosen't have a cycle" << endl;
    return  0;
}