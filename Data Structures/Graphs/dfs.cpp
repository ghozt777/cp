#include<bits/stdc++.h>
#include "./UndirectedGraph.h"
using namespace std;

int main() {
    UndirectedGraph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.dfs();
    g.dfsNonRecursive(); // order of o/p might no be the same as recursive one
}
