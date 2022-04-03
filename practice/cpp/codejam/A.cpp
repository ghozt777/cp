#include<iostream>
#include<vector>
using namespace std ;

void printGrid(vector<vector<char>> &grid){
	for(int i = 0 ; i < grid.size() ; i++){
		for(int j = 0 ; j < grid[0].size() ; j++){
			cout << grid[i][j];
		}
		cout << endl ;
	}
}

void solve(){
	int R , C ;
	cin >> R >> C ;
	int r = 2 + (R - 1) + R ;
	int c = 2 + (C - 1) + C ;
	vector<vector<char>> grid(r , vector<char>(c)) ;
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 1)){
				grid[i][j] = '.' ;
				continue ;
			}
			if(i % 2 == 0 && j % 2 == 0) grid[i][j] = '+' ;
			else if(i % 2 == 0 && j % 2 == 1) grid[i][j] = '-' ;
			else if(i % 2 == 1 && j % 2 == 0) grid[i][j] = '|' ;
			else if(i % 2 == 1 && j % 2 == 1) grid[i][j] = '.' ;
		}
	}
	printGrid(grid) ;	
}

int main(){
	int t ;
	cin >> t ;
	for(int tt = 1 ; tt <= t ; tt++){
		cout << "Case #" << tt << ":" << endl ;
		solve() ;
	}
	return 0 ;
}