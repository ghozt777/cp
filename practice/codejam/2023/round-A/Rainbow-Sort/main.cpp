/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sat Apr 15 18:11:08 IST 2023
	Link to problem / contest : 
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

void tc(){
	set<ll> s ;
	ll N ;
	cin >> N ;
	vector<ll> res ;
	vector<ll> arr(N) ;
	for(ll &x: arr) cin >> x ;
	ll last = -1 ;
	for(ll x : arr){
		if(s.find(x) == s.end()){
			last = x ;
			s.insert(x);
			res.push_back(x) ;
		}
		else if(x != last){
			cout << "IMPOSSIBLE" << endl ;
			return ;
		}
	}
	for(ll x :res) cout << x << " " ;
	cout << endl ;
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
		tc();
	}

	return EXIT_SUCCESS ;
}

