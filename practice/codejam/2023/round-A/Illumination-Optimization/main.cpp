/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sat Apr 15 18:29:55 IST 2023
	Link to problem / contest : 
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

ll INF = LLONG_MIN;

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
// const ll INF = INT_MAX;
// count set bits in a given number
template <typename T>
int cnt_set_bits(T n){int res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------------------------------------------------------------------------------

ll dp(unordered_map<ll,ll> &mem,vector<ll>&arr,ll M,ll R, ll idx = 0, ll lum = 0,ll cnt = 0){
	if(lum >= M) return cnt ;
	if(idx >= arr.size()) return INF ;
	if(arr[idx] - R > lum) return INF ;
	if(mem.find(idx) != mem.end()) return mem[idx] ;
	ll res1 = dp(mem,arr,M,R,idx + 1,lum,cnt) ;
	ll res2 = dp(mem,arr,M,R,idx + 1,arr[idx] + R,cnt + 1) ;
	if(res1 == INF || res2 == INF) return mem[idx] = max(res1,res2);
	else return mem[idx] = min(res1,res2);
}

ll tc(){
	ll M , R , N ;
	cin >> M >> R >> N ;
	vector<ll> arr(N) ;
	for(ll &x : arr) cin >> x ;
	unordered_map<ll,ll> mem ;
	return dp(mem,arr,M,R) ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	ll t ;
	cin >> t ;
	for(ll TT = 1 ; TT <= t ; TT++){
		cout << "Case #" << TT << ": " ;
		ll res = tc() ;
		res == INF ? cout << "IMPOSSIBLE" << endl : cout << res << endl ;
	}

	return EXIT_SUCCESS ;
}

