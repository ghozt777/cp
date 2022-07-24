/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Tue Jul  5 18:39:06 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1131
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
 
void addEdge(int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
 
//-----------------------------------------------------------------------------------------------

vector<int> bfs(int s){
	set<int> vis;
	vis.insert(s);
	queue<pair<int,int>> q;
	q.push({s,0});
	pair<int,int>last;
	while(!q.empty()){
		last=q.front();
		q.pop();
		for(int x:adj[last.first]){
			if(vis.find(x)==vis.end()){
				vis.insert(x);
				q.push({x,last.second+1});
			}
		}
	}
	return vector<int>({last.first,last.second});
}
 
void solve(){
	// to execute for each test case
	int n;
	cin>>n;
	init(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		addEdge(u-1,v-1);
	}
	vector<int> end1=bfs(0);
	vector<int> end2=bfs(end1[0]);
	cout<<end2[1]<<endl;
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