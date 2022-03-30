#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int bruteforce(vi& weights, vi& values, int curr, int limit, int idx){
    if(idx < 0) return 0;
    if(curr > limit) return 0;
    int ans1 = INT_MIN, ans2;
    if(curr + weights[idx] <= limit) ans1 = values[idx] + bruteforce(weights, values, curr + weights[idx], limit, idx - 1);
    ans2 = bruteforce(weights, values, curr, limit, idx - 1);
    return max(ans1, ans2);
}

int bruteforce(vi weights, vi values, int limit){
    // TC : O(2^n) : Exponential
    // maximize the value for a given constraint on total weight -> you can either pick an item or leave it -> 0 or 1
    return bruteforce(weights, values, 0, limit, weights.size() - 1);
}


int main(){
    vi values = { 10, 40 , 30 , 50 };
    vi weights = { 5, 4, 6, 3 };
    int limit = 10;
    cout << bruteforce(weights, values, limit) << endl;
}