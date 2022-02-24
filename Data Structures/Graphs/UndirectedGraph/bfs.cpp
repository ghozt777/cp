#include <bits/stdc++.h>
#include"./UndirectedGraph.h"
using namespace std;



int main() {

    // graph1 
    UndirectedGraph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.printGraph();
    cout << "bfs of graph 1 with 0 as source" << endl;
    g.bfs(0);
    cout << "bfs of graph 1 " << endl;
    g.bfs();

    // graph2 
    cout << endl;

    UndirectedGraph g1(9);
    // island1
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);

    // island2
    g1.addEdge(3, 4);
    g1.addEdge(3, 5);
    g1.addEdge(4, 5);

    // island3
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.addEdge(7, 8);

    cout << "total number of islands in 2nd graphs is " << g1.islandCount() << endl;
    cout << "bfs of graph2 " << endl;
    g1.bfs();
    return 0;
}