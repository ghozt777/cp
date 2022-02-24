#include<bits/stdc++.h>
using namespace std;

class UndirectedGraph {
    int capacity;
    vector<int>* adj;


    void dfsUtil(int root, unordered_set<int>& visited) {
        cout << root << " ";
        for (int x : this->adj[root]) {
            if (visited.find(x) == visited.end()) {
                visited.insert(x);
                dfsUtil(x, visited);
            }
        }
    }


public:
    UndirectedGraph(int capacity) {
        this->capacity = capacity;
        this->adj = new vector<int>[capacity];
    }

    void addEdge(int u, int v) {
        if (u >= capacity || v >= capacity) throw invalid_argument("u or v cant be greater than capacity");
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph() { // prints the adjacency list
        for (int i = 0; i < capacity; i++) {
            for (int x : this->adj[i]) cout << x << " ";
            cout << endl;
        }
    }

    void bfs(int root) {
        if (root >= capacity) throw invalid_argument("root cant be greater than capacity");
        unordered_set<int> visited;
        queue<int> toProcess;
        toProcess.push(root);
        visited.insert(root);
        while (!toProcess.empty()) {
            int current = toProcess.front();
            toProcess.pop();
            cout << current << " ";
            for (int x : adj[current]) {
                if (visited.find(x) == visited.end()) {
                    toProcess.push(x);
                    visited.insert(x);
                }
            }
        }
        cout << endl;
    }

    // TC : O(v + E) v : no. of vertices , E : no. of edges
    void bfs() { // useful for disconnected graphs where there is no connection from one to another
        unordered_set<int> visited;
        for (int i = 0; i < this->capacity; i++) {
            queue<int> toProcess;
            if (visited.find(i) == visited.end()) {
                toProcess.push(i);
                visited.insert(i);
            }
            while (!toProcess.empty()) {
                int current = toProcess.front();
                toProcess.pop();
                cout << current << " ";
                for (int x : adj[current]) {
                    if (visited.find(x) == visited.end()) {
                        toProcess.push(x);
                        visited.insert(x);
                    }
                }
            }
            cout << endl;
        }
    }

    int islandCount() { // returns the total number of islands in a graph 
        int ans = 0;
        unordered_set<int> visited;
        for (int i = 0; i < this->capacity; i++) {
            if (visited.find(i) == visited.end()) {
                ++ans;
                visited.insert(i);
            }
            queue<int> toProcess;
            toProcess.push(i);
            while (!toProcess.empty()) {
                int current = toProcess.front();
                toProcess.pop();
                for (int x : this->adj[current]) {
                    if (visited.find(x) == visited.end()) {
                        visited.insert(x);
                        toProcess.push(x);
                    }
                }
            }
        }
        return ans;
    }

    // TC : O(v + E) v : no. of vertices , E : no. of edges
    // useful for disconnected graphs where there is no connection from one to another
    void dfs() {
        unordered_set<int> visited;
        for (int i = 0; i < this->capacity; i++) {
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                dfsUtil(i, visited);
            }
        }
        cout << endl;
    }

    void dfsNonRecursive() {
        unordered_set<int> visited;

        for (int i = 0; i < this->capacity; i++) {

            stack<int> toProcess;

            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                toProcess.push(i);
            }

            while (!toProcess.empty()) {
                int current = toProcess.top();
                toProcess.pop();
                cout << current << " ";
                for (int x : this->adj[current]) {
                    if (visited.find(x) == visited.end()) {
                        visited.insert(x);
                        toProcess.push(x);
                    }
                }
            }
        }
        cout << endl;
    }

    // shortest parth in an unweighted graph 
    /*
    using bfs we ensure that the shortedst path is calculated as in bfs we first
    travel to the immediate neighbours and then their immidientace neighbours
    therefore increasing the distnace in a logical and progressive manner to that we
    dont need to explicitly calculate all the distances and then find the minimum amongst them
    */

    void shortestPath(int source) {
        unordered_set<int> visited;
        queue<int> toProcess;
        vector<int> distance(this->capacity, INT_MIN);
        visited.insert(source);
        toProcess.push(source);
        distance[source] = 0; // distnace of current vertex to itself = 0 
        while (!toProcess.empty()) {
            int current = toProcess.front();
            toProcess.pop();
            for (int x : this->adj[current]) {
                if (visited.find(x) == visited.end()) {
                    visited.insert(x);
                    distance[x] = distance[current] + 1; // distance of all the vertices from its source is 1 
                    toProcess.push(x);
                }
            }
        }
        cout << "For all the connected vertices with source as " << source << " : " << " the shortest paths to the corresponing vertices are : " << endl;
        for (int x : distance) cout << x << " ";
        cout << endl;
    }

    void shortestPath() {
        for (int i = 0; i < this->capacity; i++) {
            this->shortestPath(i);
        }
    }

    bool detectCycleUtil(int current , int parent , unordered_set<int> & visited){
        visited.insert(current) ;
        bool ans = false ; 
        for(int x : this->adj[current]){
            if(x != parent){
                if(visited.find(x) == visited.end()) ans = ans || detectCycleUtil(x , current , visited) ; 
                else return true ;
                if(ans) return ans ; // optimization once we find a true case we dont evaluate for other possible cases and return true
            }
        }
        return ans ;
    }

    bool detectCycle(){
        unordered_set<int> visited ;
        bool ans = false ;
        for(int i = 0 ; i < this->capacity ; i++){
            if(visited.find(i) == visited.end()) ans = ans || detectCycleUtil(i , -1 , visited) ; // parent of a root node is -1 i.e. Not Present -> for each island in a graph
            if(ans) return ans ; // optimization once we find a true case we dont evaluate for other possible cases and return true
        }
        return ans ;
    }

};
