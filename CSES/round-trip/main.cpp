/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Monday 28 November 2022 11:42:32 PM IST
	Link to problem / contest : https://cses.fi/problemset/task/1669
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

#define PB push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
#define _max(arr) * max_element(all(x))
#define _min(arr) * min_element(all(x))
#define _max_pos(arr) max_element(all(x)) - arr.begin()
#define _min_pos(arr) min_element(all(x)) - arr.begin()
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = 1e9+7 ;
const ll INF = INT_MAX;
// count set bits in a given number
template <typename T>
int cnt_set_bits(T n){int res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------------------------------------------------------------------------------


vector<vector<ll>> adj ;
vector<bool> vis ;

void dfs(ll curr,vector<ll> &st,ll p_curr = -1){
	st.push_back(curr);
	vis[curr] = true ;
	for(ll x : adj[curr]){
		if(x == p_curr) continue;
		if(vis[x]){
			reverse(st.begin(),st.end());
			vector<ll> res ;
			set<ll> s;
			res.push_back(x);
			s.insert(x);
			for(ll y : st){
				if(s.find(y) == s.end()){
					res.push_back(y);
					s.insert(y);
				}
				else{
					res.push_back(y);
					break;
				}
			}
			cout << res.size() << "\n" ;
			for(ll y : res) cout << y +1 << " ";
			cout << endl;
			exit(0);
		}
		else dfs(x,st,curr);
	}
	st.pop_back();
	return ;
}


void tc(){
	ll N , M ;
	cin >> N >> M ;
	adj.clear();
	vis.clear();
	adj.resize(N);
	vis.resize(N,false);
	for(ll i = 0 ; i < M ; i++){
		ll u , v ;
		cin >> u >> v ;
		--u , --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<ll> st;
	for(ll i = 0 ; i < N ; i++){
		if(!vis[i]){
			dfs(i,st);
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t = 1;
	while(t--) tc() ;

	return EXIT_SUCCESS ;
}

