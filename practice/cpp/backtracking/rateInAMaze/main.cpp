/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<bool>> vvb ;

void printPath(vvb & path){
    for(auto y : path)for(int x : y) cout << x << " " ;
    cout << endl ;
}

bool isPossible(vvb &maze, vvb &path , int x , int y){
    if(x < 0 || y < 0 || x >= maze.size() || y >= maze.size()) return false ;
    if(maze[y][x] == 0 || path[y][x] == 1) return false ;
    return true ;
}

void solveMaze(vvb &maze , pair<int , int> pos , pair<int , int> target, vvb &path){
    if(pos.first < 0 || pos.second < 0 || pos.first >= maze.size() || pos.second >= maze.size()) return ;
    path[pos.second][pos.first] = 1 ;
    if(pos == target) printPath(path) ;
    if(isPossible(maze , path , pos.first , pos.second - 1)) solveMaze(maze , make_pair(pos.first , pos.second - 1) , target , path) ;
    if(isPossible(maze , path , pos.first + 1 , pos.second)) solveMaze(maze , make_pair(pos.first + 1 , pos.second) , target , path) ;
    if(isPossible(maze , path , pos.first - 1 , pos.second)) solveMaze(maze , make_pair(pos.first - 1 , pos.second) , target , path) ;
    if(isPossible(maze , path , pos.first , pos.second + 1)) solveMaze(maze , make_pair(pos.first , pos.second + 1) , target , path) ;
    path[pos.second][pos.first] = 0 ;
}


void solveMaze(vvb maze){
    const int n = maze.size() ;
    vvb path(n , vector<bool>(n , 0)) ;
    solveMaze(maze , make_pair(0,0) , make_pair(n - 1 , n - 1), path) ;
}

int main() {

	// Write your code here
    int n ;
    cin >> n ;
    vvb maze(n , vector<bool>(n , 0)) ;
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++){
        int t ;
        cin >> t ;
        maze[i][j] = t ;
    }
    solveMaze(maze) ;
    
	return 0;
}
