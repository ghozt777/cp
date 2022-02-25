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


#include <vector>
using namespace std ;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        int res = this->pq[0] ;
        int n = pq.size() ;
        swap(this->pq[0] , this->pq[n - 1]) ;
        this->pq.erase(pq.end() - 1) ;
        n = pq.size() ;
        int p = 0 ;
        while((2 * p + 2) < n){
            int c ;
            if(this->pq[2 * p + 1] <= this->pq[2 * p + 2]) c  = 2 * p + 1 ;
            else c = 2 * p + 2  ;
            if(this->pq[p] > this->pq[c]) swap(this->pq[p] , this->pq[c]) ;
            else break ;
            p = c ;
        }
        return res ;
    }
};