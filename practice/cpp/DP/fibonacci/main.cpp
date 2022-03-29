#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int fib(int n){
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

vector<int> dp(1000, -1);

int fibMemo(int n){
    if(dp[n] != -1){
        cout << "using memoized result for n = " << n << endl;
        return dp[n];
    }
    if(n <= 1) return n;
    int a = fibMemo(n - 1);
    int b = fibMemo(n - 2);
    dp[n] = a + b;
    return dp[n];
}

int main(){
    cout << fibMemo(20) << endl;
    cout << fib(20) << endl;
    return 0;
}