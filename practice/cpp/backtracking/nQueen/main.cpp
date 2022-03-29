#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<bool>>& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++) cout << board[i][j] << " ";
    }
    cout << endl;
}

bool isValid(vector<vector<bool>> &board , int x , int y){
    for(int i = y - 1 ; i >= 0 ; --i) if(board[i][x]) return false ;
    for(int i = y , j = x ; i >= 0 && j < board.size() ; --i , ++j ) if(board[i][j]) return false ;
    for(int i = y , j = x ; i >= 0 && j >= 0 ; --i , --j ) if(board[i][j]) return false ;
    return true ;
}

void nQueen(vector<vector<bool>>& board, int row){
    if(row >= board.size()){
        printBoard(board);
        return;
    }
    for(int i = 0; i < board.size(); i++){
        if(isValid(board, i, row)){
            board[row][i] = true;
            nQueen(board, row + 1);
            board[row][i] = false;
        }
    }
}

void nQueen(int n){
    vector<vector<bool>> board(n, vector<bool>(n, false));
    nQueen(board, 0);
}

int main(){
    int n;
    cin >> n;
    nQueen(n);
    return 0;
}