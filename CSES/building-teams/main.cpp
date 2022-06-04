/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sat Jun  4 16:12:42 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1668
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

#define PB emplace_back
#define PBK pop_back
#define PBC push_back
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
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}
// requires c++17
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = 10e9+7 ;


vvi adj ;
vi in ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}

void addEdge(int u , int v){
	adj[u].push_back(v) ;
	adj[v].push_back(u) ; 
	++in[u] ;
	++in[v] ;
}

void dfs(int s , int prev , vi & res){
	vis[s] = true ;
	if(prev == 1) res[s] = 2 ;
	else res[s] = 1 ;
	for(int x : adj[s]){
		if(!vis[x]){
			dfs(x , prev == 1 ? 2 : 1 , res) ;
		}
	}
}

void _in(){
	for(int i = 0 ; i < in.size() ; i++){
		cout << i << ": " << in[i] << endl ;
	}
}


void solve(){
	// to execute for each test case
	int n , m ;
	cin >> n >> m ;
	adj.resize(n) ;
	vis.resize(n , false) ;
	in.resize(n , 0) ;

	for(int i = 0 ; i < m ; i++){
		int a , b ;
		cin >> a >> b ;
		addEdge(a - 1 , b - 1) ;
	}
	
	vector<int> res(n) ;
	
	int c = 0 ; 
	
	for(int i = 0 ; i < n ; i++){
		if(!vis[i]){
			++c ;
			dfs(i , 1 , res) ;
		}
	}
	
	for(int x : res) cout << x << " " ;
	cout << endl ;
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

