// link : https://cses.fi/problemset/task/1674/
// DS Algo Used: graph , bfs , dp

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

unordered_map<int, int> dp;

int count(vi adj[], int s){
    if(dp[s]) return dp[s];
    if(adj[s].size() == 0) return 0;
    int res = adj[s].size();
    for(int x : adj[s]) res += count(adj, x);
    dp[s] = res;
    return dp[s];
}

void solve(){
    int n;
    cin >> n;
    vi adj[n];
    for(int i = 2; i <= n; i++){
        int t;
        cin >> t;
        adj[t - 1].emplace_back(i - 1);
    }
    for(int i = 1; i <= n; i++) cout << count(adj, i - 1) << " ";
}

int main(){
    solve();
    return 0;
}