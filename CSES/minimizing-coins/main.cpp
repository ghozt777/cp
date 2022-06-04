/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun Jun  5 00:34:37 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1634
*/


#include<bits/stdc++.h>
using namespace std ;
const int INF = INT_MAX ;
const int _size = pow(10 ,6) + 1 ;
vector<int> dp(_size , INF) ;

int bruteforce(int n , vector<int> & coins){
	if(n == 0) return 0 ;
	if(n < 0) return INF ;
	if(dp[n] != INF) return dp[n] ;
	int res = INF ;
	for(int x : coins) res = min(res , bruteforce(n - x , coins)) ;
	if(res == INF) return INF ;
	return dp[n] = 1 + res ;
}

int _dp(int x , vector<int> & coins){
	vector<int> dp(x + 1 , INF) ;
	dp[0] = 0 ;
	for(int i = 0 ; i <= x ; i++){
		int resI = INT_MAX ;
		for(int c : coins){
			if((i - c) >= 0){
				resI = min(resI , dp[i - c]) ;
			}
		}
		if(resI != INF) dp[i] = 1 + resI ;
	}
	return dp[x] ;
}


void solve(){
	// to execute for each test case
	int n , x ;
	cin >> n >> x ;
	vector<int> coins(n) ;
	for(auto & a : coins) cin >> a ;
	int res = _dp(x , coins) ;
	res == INF ? cout << -1 << endl : cout << res << endl ;
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

