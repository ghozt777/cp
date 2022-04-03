#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll ;

using namespace std ;

void solve(){
	ll n ;
	cin >> n ; 
	vector<ll> a(n) ;
	for(ll i = 0 ; i < n ; i++) cin >> a[i] ;
	sort(a.begin() , a.end()) ;
	ll res = 0 ;
	ll last = 1 ;
	for(int i = 0 ; i < n ; i++){
		if(last <= a[i]){
			++res ;
			++last ;
			if(res > a[n - 1]){
				 res = a[n - 1];
				 break ;
			}
		}
	}
	cout << res << endl ;
	return ;
}


int main(){
	int t ;
	cin >> t ;
	for(int tt = 1 ; tt <= t ; tt++){
		cout << "Case #" << tt << ": "  ;
		solve() ;
	}
	return 0 ;
}