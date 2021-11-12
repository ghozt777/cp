#include<bits/stdc++.h>
using namespace std ;

typedef vector<vector<int>> vvi ;
#define f(itr,n) for(int itr = 0 ; itr < n ; itr++)

bool solve(vvi&) ;
bool isPossible(vvi& , int , int , int) ;
void printBoard(vvi&) ;

void LeetCodeSolver() ;

void solveSudoku(vector<vector<char>>&) ;
bool util(vector<vector<char>>&) ;
bool check(vector<vector<char>>& , int , int , int) ;
void printLC(vector<vector<char>>&) ;


int main() {

	vvi board = {
                {5, 3, 0, 0, 7, 0, 0, 0, 0},
                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                {8, 0, 3, 0, 1, 0, 0, 8, 3},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 0, 0}
        	};
        cout << "Press 1 for Demo 0 for Leetcode : " ;
        int n ; cin >> n ;
        if(n == 1){
        	solve(board) ;
        	printBoard(board) ;
        }
        else LeetCodeSolver() ;

	return 0 ;
}


bool solve(vvi& board) {
	bool f = false ;
	int r , c ;
	f(i , size(board)){
		f(j , size(board)) {
			if(board[i][j] == 0){
				r = i ;
				c = j ;
				f = true ;
				break ;
			}
		}
		if(f) break ;
	}
	if(!f) return true ;
	f(i,10){
		if(isPossible(board , r , c , i+1)){
			board[r][c] = i + 1 ;
			if(solve(board)) return true ;
			else board[r][c] = 0 ;
		}
	}
	return false ;
}

bool isPossible(vvi& board, int r , int c , int x){
	f(i , size(board)) if(board[i][c] == x) return false ;
	f(i , size(board)) if(board[r][i] == x) return false ; 
	int n = sqrt(size(board)) ;
	int rStart = r - r%n ;
	int cStart = c - c%n ; 
	f(i , n)f(j , n) if(board[rStart + i][cStart + i] == x) return false ;
	return true ;
}

void printBoard(vvi& board){
	for(auto x : board){
		for(int n : x)
			cout << n << " " ;
		cout << "\n" ;
	}
}



void LeetCodeSolver(){
	cout << "Leetcode Solution:\n" ;
	vector<vector<char>> board_lc = {
        	{'5','3','.','.','7','.','.','.','.'},
        	{'6','.','.','1','9','5','.','.','.'},
        	{'.','9','8','.','.','.','.','6','.'},
        	{'8','.','.','.','6','.','.','.','3'},
        	{'4','.','.','8','.','3','.','.','1'},
        	{'7','.','.','.','2','.','.','.','6'},
        	{'.','6','.','.','.','.','2','8','.'},
        	{'.','.','.','4','1','9','.','.','5'},
        	{'.','.','.','.','8','.','.','7','9'}
    } ;
    solveSudoku(board_lc) ;
    printLC(board_lc) ;
    return ;
}


void solveSudoku(vector<vector<char>>& board) {
	util(board) ;
}

bool util(vector<vector<char>>& board){
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			if(board[i][j] == '.'){
				for(int k = 1 ; k <= 9 ; k ++){
					if(check(board , i , j , k)){
						board[i][j] = k +'0' ;
						if(util(board)) return true ; // check for furthur solutions
						board[i][j] = '.' ; // backtracking : if this particular solution causes to create an obsolete solution then we need to backtrack else return true or the sudoku is solved
					}
				}
				return false ; // none of the numbers can be placed in the empty spot hence it cant be furthur solved 
			}
		}
	}
	return true ; // if both of the for loops pass then the sudoku is solved
}

bool check(vector<vector<char>>& board , int r , int c , int x){
	for(int i = 0 ; i < 9 ; i++) if(board[i][c] == x + '0') return false ;
	for(int i = 0 ; i < 9 ; i++) if(board[r][i] == x +'0') return false ; 
	int rStart = r - r%3 ;
	int cStart = c - c%3 ; 
	for(int i = 0 ; i < 3 ; i++) for(int j = 0 ; j < 3 ; j++) if(board[rStart + i][cStart + j] == x + '0') return false ;
	return true ;
}

void printLC(vector<vector<char>>& b){
	for(auto x : b){
		for(auto y : x){
			cout << y << " " ;
		}
		cout << "\n" ;
	}
}

