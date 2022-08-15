/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Thu Aug  4 13:00:16 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1620
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = uint64_t ;
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

bool check(vector<ll>&arr,ll time,ll t){
	ll curr=0;
	for(ll x:arr){
		curr+=time/x;
		if(curr>=t)return true;
	}
	return curr>=t;
}

void tc(){
	ll n,t;
	cin>>n>>t;
	vector<ll> arr(n);
	read(arr);
	ll res=0;
	sort(all(arr));
	ll start=0ll;
	ll end=accumulate(all(arr),(ll)0)*t;
	while(start<=end){
		ll mid=start+(end-start)/2;
		if(check(arr,mid,t)){
			res=mid;
			end=mid-1;
		}
		else start=mid+1;
	}
	cout<<res<<endl;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t=1;
	while(t--) tc() ;

	return EXIT_SUCCESS ;
}

