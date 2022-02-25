#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void testCase(int) ;

int main() {
    int t ;
    cin >> t ;
    for(int i = 1 ; i <= t ; i++) testCase(i) ;
}

void testCase(int t){
    int n ;
    cin >> n ;
    vector<int> arr(n , 0) ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
    int cost = 0 ;
    for(int i = 0 ; i < n - 1 ; i++){
        int j = min_element(arr.begin() + i , arr.end()) - arr.begin()  ; // index of the minimum element
        cost += (j - i) + 1 ;
        reverse(arr.begin() + i , arr.begin() + j + 1) ;
    }
    cout << "Case #" << t << ": " << cost << endl ;
}