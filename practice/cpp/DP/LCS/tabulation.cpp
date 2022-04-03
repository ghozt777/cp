#include<bits/stdc++.h>
using namespace std ;

void solve(){
	string s1 , s2 ;
	cin >> s1 >> s2 ;
	const int n = s1.length() ;
	const int m = s2.length() ;
	int dp[n + 1][m + 1] ;
	for(int i = 0 ; i <= n ; i++) dp[i][0] = 0 ;
	for(int i = 0 ; i <= m ; i++) dp[0][i] = 0 ;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m ; j++){
			if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1] ;
			else dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j]) ;
		}
	}
	cout << dp[n][m] << endl;
}


int main(){
	solve() ;
	return 0 ;
}