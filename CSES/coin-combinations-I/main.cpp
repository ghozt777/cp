/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun Jun  5 13:45:35 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1635
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
#define what_is(x) cout << #x << ": " << x << endl ;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}
// requires c++17
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = pow(10,9)+7 ;
const ll INF = INT_MAX ;

vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}


int bruteforce(int x , vi & coins){
	if(x == 0) return 1 ;
	if(x < 0) return 0 ;
	int res = 0 ;
	for(int c : coins) res += bruteforce(x - c , coins) ;
	return res ;
}

ll _dp(ll x , vector<ll> & coins){
	vector<ll> dp(x + 1 , 0) ;
	dp[0] = 1 ;
	for(ll i = 1 ; i <= x ; i++){
		for(ll c : coins){
			if(i - c >= 0){
				dp[i] = dp[i - c] % MOD + dp[i] % MOD ;
			}
		}
	}
	return dp[x] % MOD ;
}

void solve(){
	// to execute for each test case
	ll n , x ;
	cin >> n >> x ;
	vector<ll> coins(n) ;
	read(coins) ;
	// int res = bruteforce(x , coins) ;
	ll res = _dp(x , coins) ;
	cout << res << endl ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t = 1 ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

