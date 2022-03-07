#include<iostream>
#include "./minHeap.h"

using namespace std ;

int main(){
    MinHeap mh ;
    mh.insert(10) ;
    mh.insert(20) ;
    mh.insert(15) ;
    mh.insert(40) ;
    mh.insert(50) ;
    mh.insert(100) ;
    mh.insert(25) ;
    mh.insert(45) ;
    mh.insert(12) ;

    mh.print() ;

    return 0 ;
}