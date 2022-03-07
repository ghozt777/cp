#include<bits/stdc++.h>
#include "./minHeap.h"

using namespace std;


int main() {
    MinHeap mh;
    mh.insert(20);
    mh.insert(70);
    mh.insert(60);
    mh.insert(35);
    mh.insert(40);
    mh.insert(80);
    mh.insert(25);
    mh.insert(30);
    mh.insert(32);
    mh.insert(100);
    mh.print();
    cout << "after deleting 40 and 70 : ";
    mh.deleteKey(4);
    mh.deleteKey(7);
    mh.print();
    while (!mh.isEmpty()) {
        int x = mh.extractMin();
        cout << "current min : " << x << endl;
    }
    return 0;
}