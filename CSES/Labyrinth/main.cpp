/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Fri Jun  3 18:10:16 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1193/
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

vector<vector<char>> grid ;

inline bool ok(int i , int j){
	if(i < 0  || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#') return false ;
	return true ;
}

void bfs(){

	int n , m;
	cin >> n >> m ;
	
	grid.resize(n , vector<char>(m)) ;
	
	pi start , end ;
	
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			cin >> grid[i][j] ;
			if(grid[i][j] == 'A') start = {i,j} ;
			if(grid[i][j] == 'B') end = {i,j} ;
		}
	
	queue<pi> q ;
	q.push(start) ;
	
	vector<int> dy = {-1 , 1 , 0 , 0} ;
	vector<int> dx = {0 , 0 , -1 , 1} ;
	vector<char> d = {'U' , 'D' , 'L' , 'R'} ;
	vector<vector<int>> p(n , vector<int>(m , -1)) ; // parent array to backtrack
	
	while(!q.empty()){
		int i = q.front().first ;
		int j = q.front().second ;
		q.pop() ;
		if(grid[i][j] == 'B') break ;
		for(int k = 0 ; k < 4 ; k++){
			int ni = i + dy[k] ;
			int nj = j + dx[k] ;
			if(ok(ni , nj)){
				grid[ni][nj] = '#' ; // !imp 
				p[ni][nj] = k ;
				q.push({ni , nj}) ;
			}
		}
	
	}
	if(p[end.first][end.second] == -1){
		cout << "NO\n" ;
		return ;
	}
	else{
		string str = "" ;
		int i = end.first ;
		int j = end.second ;
		while(make_pair(i , j) != start){
			int k = p[i][j] ;
			str += d[k] ;
			i -= dy[k] ;
			j -= dx[k] ;
		}
		reverse(str.begin() , str.end()) ;
		cout << "YES\n" ;
		cout << str.length() << "\n" ;
		cout << str << endl ; 
	}
}

void solve(){
	// to execute for each test case
	bfs() ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t = 1;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

