/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Wed Jan 25 23:26:52 PST 2023
	Link to problem / contest : https://cses.fi/problemset/task/1673
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
const ll INF = LLONG_MAX;
// count set bits in a given number
template <typename T>
int cnt_set_bits(T n){int res=0;while(n){n=n&(n-1);++res;}return res;}
 
//-----------------------------------------------------------------------------------------------
 
void dfs(ll node,vector<vector<ll>>  &adj,set<ll> &path,vector<bool>&vis){
	if(vis[node]) return ;
	vis[node] = true ;
	path.insert(node) ;
	for(ll n : adj[node]) dfs(n,adj,path,vis) ;
}
 
void tc(){
	ll N , M ;
	cin >> N >> M ;
	vector<vector<ll>> edges ;
	vector<vector<ll>> adjRev(N) ;
	for(ll i = 0 ; i < M ; i++){
		ll a, b, c ;
		cin >> a >> b >> c ; --a ; --b ;
		edges.push_back({a,b,-1 * c}) ;
		adjRev[b].push_back(a) ;
	}
	set<ll> path ;
	vector<bool> vis(N,false) ;
	dfs(N -1,adjRev,path,vis) ;
	// negate each edge and run bellman ford
	vector<ll> dist(N,INF) ;
	dist[0] = 0 ;
	for(ll i = 0 ; i <= N ; i++){
		for(auto &e :edges){
			ll from = e[0] , to = e[1] , w = e[2] ;
			if(dist[from] != INF && (dist[from] + w) < dist[to]){
				dist[to] = dist[from] + w ;
				// postivite edge cycle(in OG graph) 
				if(i == N && path.find(to) != path.end()){
					cout << -1 << endl ;
					return ;
				}
			}
		}
	}
	cout << -1 * dist[N - 1] << endl ;
}
 
int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t = 1;
	// cin >> t ;
	while(t--) tc() ;
 
	return EXIT_SUCCESS ;
}