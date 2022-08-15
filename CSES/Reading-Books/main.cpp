/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Thu Aug  4 15:23:03 IST 2022
	Link to problem / contest : https://cses.fi/problemset/
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
 
void tc(){
	ll n;
	cin>>n;
	vector<ll> arr(n);
	read(arr);
	ll res;
	bool check=false;
	if(n==1){
		cout<<2*arr[0]<<endl;
		return;
	}
	ll sum=accumulate(all(arr),(ll)0);
	for(auto x:arr)if(x>(sum-x)){
		check=true;
		break;
	}
	if(check){
		sort(all(arr));
		ll diff=INF;
		ll curr=0;
		for(ll i=0;i<n-1;i++){
			curr+=arr[i];
			diff=min(diff,abs(curr-(sum-curr)));
		}
		res=sum+diff;
	}else res=sum;
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