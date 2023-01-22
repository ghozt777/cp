/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun 22 Jan 2023 12:53:27 PM IST
	Link to problem / contest : https://cses.fi/problemset/task/1672
*/

// Solution: Floyd-Warshall Algorithm (DP) : https://www.programiz.com/dsa/floyd-warshall-algorithm


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

ll dijkstras(
	vector<vector<pair<ll,ll>>> &adj,
	ll source ,
	ll dest
){
	const ll N = adj.size() ;
	vector<ll> dist(N,INF) ;
	dist[source] = 0 ;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq ;
	pq.push({0,source});
	while(!pq.empty()){
		auto curr = pq.top() ;
		ll weight = curr.first , node = curr.second ;
		pq.pop() ;
		if(weight > dist[node]) continue ;
		for(auto e : adj[node]){
			ll x = e.second + weight ;
			if(dist[e.first] > x){
				dist[e.first] = x ;
				pq.push({x,e.first}); 
			}
		}
	}
	return dist[dest] ;
}
void tc(){
	ll N,M,Q;
	cin >> N >> M >> Q ;
	vector<vector<pair<ll,ll>>> adj(N) ;
	vector<vector<ll>> dist(N,vector<ll>(N,INF)) ;
	
	for(ll i = 0 ; i < M ; i++){
		ll a , b , c ;
		cin >> a >> b >> c ;
		--a, --b ;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
		dist[a][b] = min(dist[a][b],c);
		dist[b][a] = min(dist[b][a],c);
	}

	for(ll i = 0 ; i < N ; i++) dist[i][i] = 0 ;

	for(ll k = 0 ; k < N ; k++){
		for(ll i = 0 ; i < N ; i++){
			for(ll j = 0 ; j < N ; j++){
				dist[i][j] = min(dist[i][j] ,(dist[i][k] != INF && dist[k][j] != INF) ? (dist[i][k] + dist[k][j]) : INF) ;
			}
		}
	}

	for(ll i = 0 ; i < Q ; i++){
		ll a , b ;
		cin >> a >> b ;
		--a , --b;
		ll res = min(dist[a][b],dist[b][a]) ;
		cout << (res >= INF ? -1 : res) << endl ;
	}
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

