/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Tue Jun  7 17:18:43 IST 2022
	Link to problem / contest : https://codeforces.com/problemset/problem/233/A
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


vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}


void solve(){
	// to execute for each test case
    int n ;
    cin >> n ;
    if(n % 2 == 1){
        cout << -1 << endl ;
        return ;
    }
    vi arr(n) ;
    for(int i = 1 ; i <= n ; i++) arr[i - 1] = i ;
    for(int i = 0 ; i < n - 1 ;i += 2) swap(arr[i] , arr[i + 1]) ;
    for(int x : arr) cout << x << " " ;
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

