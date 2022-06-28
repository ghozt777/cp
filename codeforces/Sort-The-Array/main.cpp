/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Mon Jun 27 16:13:56 IST 2022
	Link to problem / contest : https://codeforces.com/problemset/problem/451/B
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
bool check(vi&arr , vi&sorted,int start,int end){
	if(start>=end) return true;
	for(int i=0;i<=end-start;i++) if(arr[end-i]!=sorted[start+i]) return false;
	return true;
}
void solve(){
	// to execute for each test case
	int n;
	cin>>n;
	vi arr(n) ;
	read(arr);
	vi sorted(arr);
	sort(sorted.begin(),sorted.end());
	int start=0;
	int end=n-1;
	while(start<=end&&arr[start]==sorted[start])++start;
	while(end>=start&&arr[end]==sorted[end])--end;
	if(check(arr,sorted,start,end)){
		if(start>=end) start=0,end=0 ;
		cout<<"yes\n"<<start+1<<" "<<end+1<<"\n" ;
	}
	else cout<<"no\n";
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

