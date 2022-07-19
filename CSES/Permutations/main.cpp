/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Tue Jul 19 17:00:07 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1070
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

#define REP(i,s,e) for(int i=s;i<=e;i++)
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
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = pow(10,9)+7 ;
// graphs
vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}
// count set bits in a given number
template <typename T>
int cnt_set_bits(T n){int res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------------------------------------------------------------------------------

void solve(){
	// to execute for each test case
	ll n;
	cin>>n;
	if(n<=3){
		if(n==1)cout<<1;
		else cout<<"NO SOLUTION";
		return;
	}
	vector<ll>odd;
	vector<ll>even;
	ll curr_odd=1;
	ll curr_even=2;
	while(curr_odd<=n){
		odd.push_back(curr_odd);
		curr_odd+=(ll)2;
	}
	while(curr_even<=n){
		even.push_back(curr_even);
		curr_even+=(ll)2;
	}
	reverse(odd.begin(),odd.end());
	reverse(even.begin(),even.end());
	for(auto x:odd)cout<<x<<" " ;
	for(auto x:even)cout<<x<<" " ; 
	cout<<endl;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
    cout << std::fixed;
    cout << std::setprecision(12);
	int t=1;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

