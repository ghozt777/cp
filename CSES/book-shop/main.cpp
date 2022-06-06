/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun Jun  5 16:26:32 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1158
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
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}

int bruteforce(int curr , int n , int left_money , vi & price , vi & pages){
	if(n == 0) return curr ;
	int res = INT_MIN ;
	if(left_money >= price[n - 1]) res = max({ bruteforce(curr + pages[n - 1] , n - 1 , left_money - price[n - 1] , price , pages) , bruteforce(curr , n - 1 , left_money , price , pages) }) ;
	else res = bruteforce(curr , n - 1 , left_money , price , pages) ;
	return res ;
}

int _dp(int x , vi & prices , vi & pages){
	const int n = prices.size() ;
	// states : size_of_array , max_amount_of_money ;
	vector<vector<int>> dp(n + 1 , vector<int>(x + 1 , 0)) ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= x ; j++){
			if(j >= prices[i - 1]) dp[i][j] = max(dp[i - 1][j] , pages[i - 1] + dp[i - 1][j - prices[i - 1]]) ;
			else dp[i][j] = dp[i - 1][j] ; 
		}
	}
	return dp[n][x] ;
}

void solve(){
	// to execute for each test case
	int n , x ;
	cin >> n >> x ;
	vi price(n) ;
	vi pages(n) ;
	read(price) ;
	read(pages) ;
	// int res = bruteforce(0 , n , x , price , pages) ;
	int res = _dp(x , price , pages) ;
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

