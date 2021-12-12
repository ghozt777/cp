#include <iostream>
#include <cstring>
using namespace std;


int solve(int n , int k){
    int s = 0 ;
     for(int i = 1 ; i <= n ; i++){
        if(i%k != 0) s += i ;
    }
    return s ;
}

void Run() {
    int t ;
    cin >> t ;
    while(t--){
        int n , k ;
        cin >> n >> k ;
        cout << solve(n , k) << endl ;
    }
}
int main() {
    Run() ;
    return 0 ;
}