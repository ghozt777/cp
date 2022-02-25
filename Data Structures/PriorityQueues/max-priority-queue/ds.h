//  IMPLEMENTED USING BINARY HEAPS : A FORM OF CBT(complete Bianry Tree)
/*
    A binary heap is defined as a binary tree with two additional constraints:[3]

    Shape property: a binary heap is a complete binary tree; that is, all levels of the tree, except possibly the last one (deepest) are fully filled, and, if the last level of the tree is not complete, the nodes of that level are filled from left to right.
    Heap property: the key stored in each node is either greater than or equal to (≥) or less than or equal to (≤) the keys in the node's children, according to some total order.
*/

 // gfg : https://www.geeksforgeeks.org/binary-heap/
 // wiki : https://en.wikipedia.org/wiki/Binary_heap



// to get parent index from a child index : parentIndex = (2 * childIndex - 1) / 2 ;
// to get child index from a parent index : leftChildIndex = parentIndex * 2 + 1 , rightChildIndex = 2 * parentIndex + 2 

#include<vector>
using namespace std ;
class PriorityQueue {
    // Declare the data members here

    vector<int> pq ;
    
   public:
    PriorityQueue() {
        // Implement the constructor here
        /* DOES SHIT */
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        this->pq.push_back(element) ;
        const int n = this->pq.size() ;
        int c = n - 1 ;
        while(c > 0){
            int p = (c - 1) / 2 ;
            if(this->pq[p] < this->pq[c]) swap(this->pq[p] , this->pq[c]) ;
            else break ;
            c = p ; 
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(this->isEmpty()) return -2147483648 ;
        return this->pq[0] ;
    }

    int removeMax() {
        // Implement the removeMax() function here
        int res = this->pq[0] ;
        swap(this->pq[0] , this->pq[pq.size() - 1]) ;
        this->pq.erase(pq.end() - 1) ;
        int n = this->pq.size() ;
        int p = 0 ;
        while((2 * p + 2 ) < n){
            int c ;
            if(this->pq[2 * p + 1] >= this->pq[2 * p + 2]) c = 2 * p + 1 ;
            else c = 2 * p + 2 ;
            if(this->pq[p] < this->pq[c]) swap(this->pq[p] , this->pq[c]) ;
            else break ;
            p = c ;
        }
        return res ;
    }

    int getSize() { 
        // Implement the getSize() function here
        return this->pq.size() ;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return this->pq.size() == 0 ;
    }
};