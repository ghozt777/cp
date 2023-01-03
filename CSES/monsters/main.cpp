// link : https://cses.fi/problemset/task/1194


#include<bits/stdc++.h>

using namespace std ;
using ll = long long ;
using pllc = pair<char,pair<ll,ll>> ;


void solve(vector<vector<char>> & grid){
	
	const ll N = grid.size() , M = grid[0].size() ;
	
	vector<vector<ll>> monster(N,vector<ll>(M,LLONG_MAX)) , player(N,vector<ll>(M,LLONG_MAX));
	vector<vector<pllc>> parent(N,vector<pllc>(M));
	vector<vector<bool>> vis(N,vector<bool>(M,false));
	
	vector<vector<ll>> dirs = {
	 {1,0},
	 {-1,0},
	 {0,1},
	 {0,-1}	
	};
	
	queue<pair<ll,ll>> q;
	for(ll i = 0 ; i < N ; i++){
		for(ll j = 0 ; j < M ; j++){
			if(grid[i][j] == 'M'){
				 q.push({i,j}) ;
				 vis[i][j] = true ;
			}
		}
	}
	
	ll curr_time = 0 ;
	while(!q.empty()){
		const ll n = q.size() ;
		for(ll i = 0 ; i < n ; i++){
			auto [x,y] = q.front() ;
			q.pop() ;
			monster[x][y] = curr_time ;
			for(auto & d : dirs){
				ll dx = x + d[0] , dy = y + d[1] ;
				if(dx >= 0 && dy >= 0 && dx < N && dy < M && !vis[dx][dy] && grid[dx][dy] != '#'){
					 q.push({dx,dy}) ;
					 vis[dx][dy] = true;
				}
			}
		}
		++curr_time ;
	}
	
	
	
	curr_time = 0 ;
	
	for(ll i = 0 ; i < N ; i++){
		for(ll j = 0 ; j < M ; j++){
			vis[i][j] = false;
			if(grid[i][j] == 'A'){
				 q.push({i,j}) ;
				 vis[i][j] = true ;
				 parent[i][j] = {' ' , {-1,-1}};
			}
		}
	}
	
	
	
	while(!q.empty()){
		const ll n = q.size() ;
		for(ll i = 0 ; i < n ; i++){
			auto [x,y] = q.front() ;
			q.pop() ;
			player[x][y] = curr_time ;
			for(int j = 0 ; j < dirs.size() ; j++){
				ll dx = x + dirs[j][0] , dy = y + dirs[j][1] ;
				if(dx >= 0 && dy >= 0 && dx < N && dy < M && !vis[dx][dy] && grid[dx][dy] != '#'){
					 q.push({dx,dy}) ;
					 vis[dx][dy] = true;
					 parent[dx][dy] = {
						 j == 0 ? 'D' : j == 1 ? 'U' : j == 2 ? 'R' : 'L' ,
						 {x,y}
					 } ;
				}
			}
		}
		++curr_time ;
	}	
	
	
	ll min = LLONG_MAX , mx , my;
	
	for(ll i = 0 ; i < N ; i++){
		if(player[i][0] != -1 && player[i][0] < monster[i][0] && player[i][0] < min){
			min = player[i][0] ;
			mx = i , my = 0 ;
		}
		if(player[i][M - 1] != -1 && player[i][M - 1] < monster[i][M - 1] && player[i][M - 1] < min){
			min = player[i][M - 1] ;
			mx = i , my = M - 1 ;
		}
	}
	
	
	for(ll i = 0 ; i < M ; i++){
		if(player[0][i] != -1 && player[0][i] < monster[0][i] && player[0][i] < min){
			min = player[0][i] ;
			mx = 0 , my = i ;
		}
		if(player[N - 1][i] != -1 && player[N - 1][i] < monster[N - 1][i] && player[N - 1][i] < min){
			min = player[N - 1][i] ;
			mx = N - 1 , my = i ;
		}
	}
	
	
	if(min == LLONG_MAX){
		cout << "NO\n" ;
		return ; 
	}
	
	
	cout << "YES\n" << min << endl ;
	
	string res = "" ;

	while(mx != -1){
		auto p = parent[mx][my] ;
		if(p.first != ' ') res += p.first ;
		mx = p.second.first , my = p.second.second ;
	}

	reverse(res.begin(),res.end()) ;

	cout << res << endl ;
}


int main(){
	
	ll N , M ;
	cin >> N >> M ;
	
	vector<vector<char>> grid(N , vector<char>(M)) ;
	
	for(ll i = 0 ; i < N ; i++)
		for(ll j = 0 ; j < M ; j++){
			char _in ;
			cin >> _in ;
			grid[i][j] = _in ;
		}
		
		solve(grid);
	
	return EXIT_SUCCESS;
}