#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> cbt;
public:
    MinHeap() {
        // 
    }
    bool isEmpty() {
        return this->size() == 0;
    }
    int size() {
        return this->cbt.size();
    }
    int left(int i) {
        return 2 * i + 1 < cbt.size() ? 2 * i + 1 : -1;
    }
    int right(int i) {
        return 2 * i + 2 < cbt.size() ? 2 * i + 2 : -1;
    }
    int parent(int i) {
        return (int)((i - 1) / 2) < cbt.size() ? (int)((i - 1) / 2) : -1;
    }
    void insert(int x) {
        cbt.emplace_back(x); //  to abide by CBT
        // to abide by min heap prop
        int c = cbt.size() - 1;
        while (c > 0) {
            int p = parent(c);
            if (cbt[p] > cbt[c]) swap(cbt[p], cbt[c]);
            else break;
            c = p;
        }
    }
    void print() {
        for (int x : cbt) cout << x << " ";
        cout << endl;
    }

    void decreaseKey(int pos, int k) { // decreases the value of a node at a particular index
        if (pos >= this->cbt.size()) throw invalid_argument("index can't be greater than the size of the heap!");
        this->cbt[pos] = k;
        int c = pos;
        while (c > 0) {
            int p = this->parent(c);
            if (this->cbt[c] < this->cbt[p]) swap(this->cbt[c], this->cbt[p]);
            else break;
            c = p;
        }
    }

    int extractMin() { //  returns ans removes the mimimum element in the pq

        if (this->isEmpty()) throw invalid_argument("cant extract from empty !");;
        int _min = cbt[0];
        swap(cbt[0], cbt[this->size() - 1]);
        cbt.pop_back();
        int c1, c2, s, p;
        p = 0;
        while (p < (int)cbt.size()) {
            c1 = left(p);
            c2 = right(p);
            if (c1 != -1 && c2 != -1) s = cbt[c1] < cbt[c2] ? c1 : c2;
            else if (c1 == -1 && c2 != -1) s = c2;
            else if (c2 == -1 && c1 != -1) s = c1;
            else break;
            if (cbt[s] < cbt[p]) swap(cbt[s], cbt[p]);
            else break;
            p = s;
        }
        return _min;
    }

    void deleteKey(int pos) {
        if (pos >= this->cbt.size()) throw invalid_argument("index can't be greater than the size of the heap!");
        if (this->isEmpty()) throw invalid_argument("heap is empty!");
        decreaseKey(pos, INT_MIN); // bubble it up the tree to the very first node ;
        int check = extractMin(); // remove the first node essentially deleting the node to be deleted
        if (check == INT_MIN) cout << "Successfully removed element !" << endl;
        else cout << "Error occured while removing the element" << endl;
    }

    void minHeapify(int pos) {
        while (pos < this->size()) {
            int c1 = left(pos);
            int c2 = right(pos);
            int s;
            if (c1 == -1 && c2 != -1) s = c2;
            else if (c2 == -1 && c1 != -1) s = c1;
            else if (c1 != -1 && c2 != -1) s = cbt[c1] < cbt[c2] ? c1 : c2;
            else break;
            if (cbt[s] < cbt[pos]) {
                swap(cbt[s], cbt[pos]);
                minHeapify(s);
            }
        }
    }

    void 
};