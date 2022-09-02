/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Mon Aug 22 13:13:18 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1746
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
	ll N,M;
	cin>>N>>M;
	vector<ll> A(N);
	read(A);
	vector<vector<ll>> dp(N,vector<ll>(M+1,0)); // dp states : [current_index][value_at_current_index]
	for(ll i=0;i<N;i++){
		if(A[i]){
			// we can't add any vlaue here
			ll j=A[i];
			// if we are not at the first element we can still add different array configs based on the rule abs(arr[i]-arr[i-1])<=1
			if(i!=0)for(ll k=max((ll)1,j-1);k<=min(M,j+1);k++) dp[i][j]=dp[i][j]%MOD+dp[i-1][k]%MOD;
			// there only 1 config for this case
			else dp[i][j]=1;
		}
		else{
			if(i==0){
				// we can add each number once in the first position
				for(ll k=1;k<=M;k++) dp[i][k]=1;
			}
			// we can add configs based on the previous config according to the rule of abs(arr[i]-arr[i-1])<=1 i.e. for a value lets say j we can add config from the array od size one smaller than the current one by looking up no of ways to make (j-1,j,j+1) as the last elemetn
			else{
				for(ll j=1;j<=M;j++){
					for(ll k=max((ll)1,j-1);k<=min(M,j+1);k++) dp[i][j]=dp[i][j]%MOD+dp[i-1][k]%MOD;
				}
			}
		}
	}
	ll res=0;
	// finally we sum of the total number of different ways with size N and numbers 1 to M as the last elelemt
	for(ll x:dp[N-1]) res=res%MOD+x%MOD;
	cout<<res%MOD<<endl;
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

