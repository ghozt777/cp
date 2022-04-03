#include<bits/stdc++.h>
using namespace std ;

// question: 
// get the length of the longest subsequence of a string that is also a pallindrome

int LCS(string s1 , string s2){
	const int n = s1.length() ;
	const int m = s2.length() ;
	int dp[n + 1][m + 1] ;
	for(int i = 0 ; i <= n ; i++) dp[i][0] = 0 ;
	for(int i = 0 ; i <= m ; i++) dp[0][i] = 0 ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1] ;
			else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
		}
	}
	return dp[n][m] ;
}

void solve(){
	string s ;
	cin >> s ;
	string rev(s) ;
	reverse(rev.begin() , rev.end()) ;
	int res = LCS(s , rev) ;
	cout << res << endl ;
	return ;
}

int main(){
	solve() ;
	return 0 ;
}