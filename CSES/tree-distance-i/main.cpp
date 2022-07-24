/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Wed Jul  6 00:07:16 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1132
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
// count set bits in a given number
template <typename T>
int cnt_set_bits(T n){int res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------3------------------------------------------------------------------------

const int SZ=2*pow(10,5)+1;
vector<int> dp(SZ,-1);

void addEdge(vector<vector<int>>&adj,int u,int v){
	adj[u].push_back(v) ;
	adj[v].push_back(u) ;
}

int bfs(int s,vector<vector<int>>&adj){
	if(dp[s]!=-1) return dp[s];
	vector<bool> vis(adj.size(),false);
	vis[s]=true;
	int res=-1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int n=q.size();
		++res;
		for(int i=0;i<n;i++){
			int curr=q.front();
			q.pop();
			for(int x:adj[curr]){
				if(!vis[x]){
					vis[x]=true;
					q.push(x);
				}
			}
		}
	}
	return dp[s]=res;
}

void solve(){
	// to execute for each test case
	int n;
	cin>>n ;
	vector<vector<int>> adj(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		addEdge(adj,u-1,v-1);
	}
	for(int i=0;i<n;i++){
		cout<<bfs(i,adj)<<" ";
		// vis.resize(n,false);
	}
	cout<<endl;
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

