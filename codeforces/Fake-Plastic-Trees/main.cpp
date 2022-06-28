/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Tue Jun 28 13:56:38 IST 2022
	Link to problem / contest : https://codeforces.com/problemset/problem/1693/B
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<ll> ;
using vvi = vector<vi> ;
using pi = pair<ll , ll> ;

#define REP(i,s,e) for(ll i=s;i<=e;i++)
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
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = pow(10,9)+7 ;
//-----------------------------------------------------------------------------------------------


void dfs(vector<vector<ll>>&adj,vector<ll>&self,vector<ll>&sum,vector<pair<ll,ll>>&limits,ll s){
	if(adj[s].size()==0){
		self[s]=limits[s].second;
		return;
	}
	for(ll x:adj[s]){
		dfs(adj,self,sum,limits,x);
		sum[s]+=self[x];
	}
	if(sum[s]<limits[s].first){
		self[s]=limits[s].second;
	}
	else if(sum[s]<=limits[s].second){
		self[s]=sum[s];
	}
	else self[s]=limits[s].second;
}

void solve(){
	// to execute for each test case
	ll n;
	cin>>n;
	vector<vector<ll>> adj(n) ;
	for(ll i=2;i<=n;i++){
		ll p;
		cin>>p;
		adj[p-1].PB(i-1);
	}
	vector<ll> self(n,0) ;
	vector<ll> sum(n,0) ;
	vector<pair<ll,ll>> limits(n) ;
	for(ll i=0;i<n;i++){
		ll l,r;
		cin>>l>>r;
		limits[i]={l,r};
	}
	dfs(adj,self,sum,limits,0);
	ll ans=0;
	for(ll i=0;i<n;i++)if(self[i]>sum[i])++ans;
	cout<<ans<<endl;
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