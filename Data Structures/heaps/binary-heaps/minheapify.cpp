#include<bits/stdc++.h>

using namespace std ;

void heapify(vector<int> & arr , int idx){
    int left = 2 * idx + 1 ;
    int right = 2 * idx + 2 ;
    int smallest = idx ;
    if(left < arr.size() && arr[left] < arr[smallest]) smallest = left ;
    if(right < arr.size() && arr[right] < arr[smallest]) smallest = right ;
    if(smallest != idx){
        swap(arr[idx] , arr[smallest]) ;
        heapify(arr , smallest) ;
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6} ;
    for(int i = 0 ; i < arr.size() ; i++){
        heapify(arr , i) ;
    }
    for(int x : arr) cout << x << " " ;
    cout << endl ;
    return 0 ;
}