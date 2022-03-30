#include<bits/stdc++.h>
using namespace std;

// bruteforce solution
// TC: O(2^n)

int solve(vector<int>& arr, int sum, int n){
    if(sum == 0) return 1;
    if(n <= 0) return 0;
    return solve(arr, sum, n - 1) + solve(arr, sum - arr[n - 1], n - 1);
}

int main(){
    vector<int> arr = { 1, 2, 3, 7, 10 , 4 , 5 };
    cout << solve(arr, 12, arr.size()) << endl;
    return 0;
}