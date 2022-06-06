/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun Jun  5 15:18:27 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1638
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
const ll MOD = pow(10,9)+7 ;


vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}


// bruteforce solution
void dfs(vector<vector<char>> & grid , int i , int j , int & res){
	const int n = grid.size() ;
	if(i >= n || j >= n || grid[i][j] == '*') return ;
	if(i == n - 1 && j == n - 1){
		++res ;
		return ; 
	}
	grid[i][j] = '*' ;
	
	dfs(grid , i + 1 , j , res) ;
	dfs(grid , i , j + 1 , res) ;
	
	grid[i][j] = '.' ;
}


ll _dp(vector<vector<char>> & grid){
	if(grid[0][0] == '*') return 0 ;
	const int n = grid.size() ;
	vector<vector<ll>> dp(n + 1 , vector<ll>(n + 1 , 0)) ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i == 1 && j == 1) dp[i][j] = 1 ;
			else if(grid[i - 1][j - 1] == '*') dp[i][j] = 0 ;
			else dp[i][j] = dp[i - 1][j] % MOD + dp[i][j - 1] % MOD ;
		}
	}
	return dp[n][n] % MOD ;
}

void solve(){
	// to execute for each test case
	int n ;
	cin >> n ;
	vector<vector<char>> grid(n , vector<char>(n)) ;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> grid[i][j] ;
	// int res = 0 ;	dfs(grid , 0 , 0 , res) ;
	ll res = _dp(grid) ;
	cout << res << endl ;
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

