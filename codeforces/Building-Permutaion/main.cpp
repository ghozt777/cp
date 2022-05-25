/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
        Time: Wed May 25 12:53:04 IST 2022
	Link to problem / contest : https://codeforces.com/problemset/problem/285/C
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = int64_t ;
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
	ll n ;
	cin >> n ;
	vector<ll> arr ;
	vector<ll> nt ;
	unordered_set<ll> t ;
	for(ll i = 1 ; i <= n ; i++){
		ll a ;
		cin >> a ;
		if((a <= 0 || a > n) || t.find(a) != t.end()) arr.PB(a) ;
		else t.insert(a) ;
	}
	for(ll i = 1 ; i<= n ; i++) if(t.find(i) == t.end()) nt.PB(i) ;
	sort(arr.begin(),arr.end()) ;
	ll res = (ll)0 ;
	ll start , end ;
	start = 0 ;
	end = nt.size() - 1 ;
	int curr = 0 ;
	int c = 0 ;
	for(ll i = 0 ; i < arr.size() ; i++) res += abs(arr[i] - nt[i]) ;
	cout << res << endl ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	solve() ;

	return EXIT_SUCCESS ;
}

