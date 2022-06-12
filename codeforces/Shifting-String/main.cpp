/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Thu Jun  9 10:49:25 IST 2022
	Link to problem / contest : https://codeforces.com/contest/1690/problem/F
*/

/*
	
	For video solution watch : 
	https://www.youtube.com/watch?v=kO0NEn-WZ3Y
	
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<ll> ;
using vvi = vector<vi> ;
using pi = pair<ll , ll> ;

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
#define what_is(x) cout << #x << ": " << x << endl ;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// requires c++17
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = pow(10,9)+7 ;


ll getCycleLength(string s){
	const ll n = s.length() ;
	ll res = 1 ;
	string t = s[n - 1] + s.substr(0 , n - 1) ;
	while(t != s){
		t = t[n - 1] + t.substr(0 , n - 1) ;
		++res ;
	}
	return res ;
}

ll lcm(ll a , ll b){
	return (a * b) / gcd(a , b) ;
}

void solve(){
	// to execute for each test case
	ll n ;
	cin >> n ;
	string s ;
	cin >> s ;
	vi p(n) ;
	for(ll i = 0 ; i < n ; i++){
		cin >> p[i] ;
		--p[i] ;
	}

	// detect cycles 

	vector<bool> vis(n , false) ;
	vvi cycles ;

	for(ll i = 0 ; i < n ; i++){
		if(!vis[i]){
			vi cycle ;
			cycle.PB(i) ;
			vis[i] = true ;
			ll curr = p[i] ;
			while(curr != i){
				vis[curr] = true ;
				cycle.PB(curr) ;
				curr = p[curr] ;
			}
			cycles.PB(cycle) ;
		}
	}

	// a string cycle may have the same characters repeated -> minimuze the cycle length

	vector<string> vs ;

	for(auto r : cycles){
		string t = "" ;
		for(ll x : r) t += s[x] ;
		vs.PB(t) ;
	}

	vi cycleLengths ;

	for(string x : vs){
		ll cycleLength = getCycleLength(x) ;
		cycleLengths.PB(cycleLength) ;
	}


	ll res = cycleLengths[0] ;
	for(ll i = 1 ; i < cycleLengths.size() ; i++) res = lcm(res , cycleLengths[i]) ;

	cout << res << endl ;

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
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

