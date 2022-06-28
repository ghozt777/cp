/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Wed Jun 15 15:25:27 IST 2022
	Link to problem / contest : https://codeforces.com/contest/1697/problem/B
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<ll> ;
using vvi = vector<vi> ;
using pi = pair<ll , ll> ;

#define REP(i,s,e) for(ll i=s;i<=e;i++)
#define EB emplace_back
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(ll i=0;i<n;i++)
#define fr(itr, n) for(ll itr=0;itr<n;itr++)
#define F(s,e) for(ll i=s;i<=e;i++)
#define c(arr,x) count(arr.begin() , arr.end() , x)
#define _max(arr) * max_element(arr.begin() , arr.end())
#define _min(arr) * min_element(arr.begin() , arr.end())
#define _max_pos(arr) max_element(arr.begin() , arr.end()) - arr.begin()
#define _min_pos(arr) min_element(arr.begin() , arr.end()) - arr.begin()
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = pow(10,9)+7 ;
// graphs
vvi adj ;
vector<bool> vis ;
void init(ll v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(ll s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}
// count set bits in a given number
template <typename T>
ll cnt_set_bits(T n){ll res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------------------------------------------------------------------------------

void solve(){
	// to execute for each test case
	ll n , q ;
	cin >> n >> q ;
	vector<ll> arr(n) ;
	read(arr) ;
	sort(arr.begin() , arr.end()) ;
	reverse(arr.begin() , arr.end()) ;
	vector<ll> prefix(n) ;
	for(int i = 0 ; i < n ; i++){
		if(i == 0) prefix[i] = arr[i] ;
		else prefix[i] = prefix[i - 1] + arr[i] ;
	}
	while(q--){
		ll x , y ;
		cin >> x >> y ;
		--x , --y ;
		ll res ; 
		if(x == y) res = prefix[x] ;
		else res = prefix[x] - prefix[x - y - 1] ;
		cout << res << endl ;
	}
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	ll t = 1 ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

