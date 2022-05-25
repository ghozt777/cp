/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777

	Link to problem / contest : 
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;


#define PB emplace_back
#define PBK pop_back
#define PBC push_back
#define MP make_pair
#define f(n) for(int i=0;i<n;i++)
#define fr(itr, n) for(int itr=0;itr<n;itr++)
#define F(s,e) for(int i=s;i<=e;i++)
#define c(arr,x) count(arr.begin() , arr.end() , x)
#define _max(arr) * max_element(arr.begin() , arr.end())
#define _min(arr) * min_element(arr.begin() , arr.end())
#define _max_pos(arr) max_element(arr.begin() , arr.end()) - arr.begin()
#define _min_pos(arr) min_element(arr.begin() , arr.end()) - arr.begin()
const ll MOD = 10e9+7 ;

vvi adj ;
vector<bool> vis ;

void init(int v){
	adj.clear() ;
	vis.clear() ;
	adj.resize(v) ;
	vis.resize(v , false) ;
}

void dfs(int s){
	vis[s] = true ;
	for(auto x : adj[s]) if(!vis[x]) dfs(x) ;
}


void solve(){
	// to execute for each test case
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush() 
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	int t ;
	cin >> t ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}
