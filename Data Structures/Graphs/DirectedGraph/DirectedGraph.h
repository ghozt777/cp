#include<bits/stdc++.h>


class DirectedGraph{
    std::vector<int> * adj ;
    int capacity ;

    public : 
    DirectedGraph(int capacity){
        this->capacity = capacity ;
        this->adj = new std::vector<int>[capacity] ;
    }

    void addEdge(int u , int v){
        // u -> v : directed edge
        if(u >= this->capacity || v >= this->capacity) throw std::invalid_argument("index is greater than the size of the graph !") ;
        this->adj[u].push_back(v) ;
    }

    void bfs(){
        std::unordered_set<int> visited ;
        std::queue<int> toProcess ;
        for(int i = 0 ; i < this->capacity ; i++){
            if(visited.find(i) == visited.end()){
                visited.insert(i) ;
                toProcess.push(i) ;
            }
            while(!toProcess.empty()){
                int current = toProcess.front();
                toProcess.pop() ;
                std::cout << current << " " ;
                for(int x : this->adj[current]){
                    if(visited.find(x) == visited.end()){
                        visited.insert(x) ;
                        toProcess.push(x) ;
                    }
                } 
            }
        }
    }

    bool detectCycleUtil(int current , std::unordered_set<int> & visited , std::unordered_set<int> & recursionStack){
        visited.insert(current) ;
        recursionStack.insert(current) ;

        // debugging puropose 
        auto debug = [](int current, std::unordered_set<int> & recursionStack){
            std::cout << "recursion stack for : " << current << " : " ;
            for(int x : recursionStack) std::cout << x << " " ;
            std::cout << std::endl ;
        } ;
        // debug(current ,recursionStack) ; //  lambda function for debugging : 

        bool ans = false ;
        for(int x : this->adj[current]){
            if(visited.find(x) == visited.end()){
                ans = ans || detectCycleUtil(x , visited , recursionStack) ;
                if(ans) return ans ;
            }
            /*
                NOTE : Since we are checking if the element is in the recusion stack -> 
                If the element is actually is in the recusion stack -> the element is visited 
                Therefore adding a condition for that inside the above if case will cause error as it will only check for elements that are not visited
                and hence we will never check for the presence of the element in the recursion stack
            */
            else if(recursionStack.find(x) != recursionStack.end()) return true ; // if there is an element that is currently there in the recursion srack -> there is a loop in the graph
        }
        recursionStack.erase(current) ; // remove element from the stack
        return ans ;
    }
    /*
        DFS Based Solution Different from Undirected Graph 
        Idea : 
        Visit every node and check if the any node points to a node that is already there in the recursion stack or not
        If there is such an element then the graph contains a loop 
        For more inshight : Draw the Recursion tree or unblock the above debugging block to visualize the output
    */
    bool detectCycle(){
        std::unordered_set<int> visited ;
        std::unordered_set<int> recursionStack ;
        bool ans = false ;
        for(int i = 0 ; i < this->capacity ; i++){
            if(visited.find(i) == visited.end()){
                ans = ans || detectCycleUtil(i , visited , recursionStack) ;
                if(ans) return ans ;
            }
        }
        return ans ;
    }

    std::vector<int> calInDegree(){
        std::vector<int> indegree(this->capacity , 0) ;
        std::unordered_set<int> visited ;
        std::queue<int> toProcess ;
        for(int i = 0 ; i < this->capacity ; i++){
            if(visited.find(i) == visited.end()){
                visited.insert(i) ;
                toProcess.push(i) ;
            }
            while(!toProcess.empty()){
                int current = toProcess.front() ;
                toProcess.pop() ;
                for(int x : this->adj[current]){
                    if(visited.find(x) == visited.end()){
                        visited.insert(x) ;
                        toProcess.push(x) ;
                    }
                    ++indegree[x] ; 
                }
            }
        }
        return indegree ;
    }

    // BFS Based
    std::vector<int> topologicalSort(){ // based on number of dependencies
        if(this->detectCycle()) throw std::logic_error("GIVEN GRAPH IS NOT A DAG ABORT !") ; 
        std::vector<int> indegree = this->calInDegree() ;
        std::queue<int> vertices_with_zero_indegree ;
        std::unordered_set<int> visited ;
        std::vector<int> res(this->capacity , -1) ;
        int count = 0 ;
        // initially add all the vertices which dont have any dependencies since they are the one to be first compiled / processed
        // i.e. vertices with indegree == 0
        for(int i = 0 ; i < this->capacity ; i++){
            if(indegree[i] == 0) vertices_with_zero_indegree.push(i) ;
        }
        while(!vertices_with_zero_indegree.empty()){
            int current = vertices_with_zero_indegree.front() ;
            vertices_with_zero_indegree.pop() ;
            res[count++] = current ;
            for(int x : this->adj[current]){
                --indegree[x] ; // since the parent vertex is processed all the vertices that are dependent on it can reduce their number of dependencies by 1
                if(indegree[x] == 0) vertices_with_zero_indegree.push(x) ; //  if during processing we find a vertex whosse current number of dependency == 0 i.e. it dosen't depend on any othe rvertex for it processing -> it means that it can br processed now and hence we can enqueue it
                // NOTE THAT THERE CAN BE MORE THAN ONE WAY FOR TOPOLOGICAL SORT FOR A GIVEN DAG
            } 
        }
        return res ;
    }

    bool detectCycleKakns(){ // cycle detection in Directed Graph Using Kahns Algo
        std::vector<int> indegree = this->calInDegree() ;
        std::queue<int> vertices_with_zero_indegree ;
        for(int i = 0 ; i < this->capacity ; i++){
            if(indegree[i] == 0) vertices_with_zero_indegree.push(i) ;
        }
        int count = 0 ;
        while(!vertices_with_zero_indegree.empty()){
            int current = vertices_with_zero_indegree.front() ;
            vertices_with_zero_indegree.pop() ;
            for(int x : this->adj[current]){
                --indegree[x] ;
                if(indegree[x] == 0) vertices_with_zero_indegree.push(x) ;
            }
            ++count ;
        }
        return count != this->capacity ;
    }

} ;