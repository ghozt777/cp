/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Mon 22 Aug 2022 12:24:14 AM IST
	Link to problem / contest : https://cses.fi/problemset/task/1746
*/
 
 
#include<bits/stdc++.h>
using namespace std ;
 
using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;
 
#define EB emplace_back
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i=0;i<n;i++)
#define fr(itr, n) for(int itr=0;itr<n;itr++)
#define F(s,e) for(int i=s;i<=e;i++)
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
 
ll res=0;
ll ub;
 
bool check(vector<ll>&arr){ 
	ll last=-1;
	for(ll &x:arr){
		if(last!=-1){
			if(abs(x-last)>1||x>ub) return false;
		}
		last=x;
	}
	return true;
}
 
 
void dfs(vector<ll>&A,ll v){
	if(v>=A.size()){
		res=res%MOD+(ll)check(A);
		return;
	}
	if(!A[v]){
		if(v==0){
			for(ll x=1;x<=ub;x++){
				ll og=A[v];
				A[v]=x;
				dfs(A,v+1);
				A[v]=og;
			}
		}
		else{
			for(ll x=max(A[v-1]-1,(ll)1);x<=min(A[v-1]+1,ub);x++){
				ll og=A[v];
				A[v]=x;
				dfs(A,v+1);
				A[v]=og;
			}
		}
	}else{
		dfs(A,v+1);
	}
}
 
ll bf(){
	ll N,M;
	cin>>N>>M;
	ub=M;
	vector<ll> A(N);
	for(auto &x:A)cin>>x;
	dfs(A,0);
	cout<<res<<endl;
}

ll dp(){
	ll N,M;
	cin>>N>>M;
	ll sz=N+1
	ll dp[sz];
	vector<ll> A(N);
	for(auto &x:A)cin>>x;
	
	cout<<dp[N]<<endl;
}
 
void solve(){
	// to execute for each test case
	bf();
}	
 
int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t=1;
	while(t--) solve() ;
 
	return EXIT_SUCCESS ;
}