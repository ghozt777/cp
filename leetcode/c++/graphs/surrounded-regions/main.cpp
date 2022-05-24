// link : https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // first convert all the border Os with a special character '*'
        const int n = board.size() ;
        const int m = board[0].size() ;
        
        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O') markBoundary(i , 0 , board) ;
            if(board[i][m - 1] == 'O') markBoundary(i , m - 1 , board) ;
        }
        
        for(int i = 0 ; i < m ; i++){
            if(board[0][i] == 'O') markBoundary(0 , i , board) ;
            if(board[n - 1][i] == 'O') markBoundary(n - 1 , i , board) ;
        }
        
        // convert all the remaining Os to Xs
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O') replaceOs(i , j , board) ;
            }
        }
        
        // replace all the '*'s with 'O's
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == '*') board[i][j] = 'O' ;
            }
        }
    }
    
    void markBoundary(int i , int j , vector<vector<char>> & board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return ;
        board[i][j] = '*' ;
        if(i - 1 >= 0 && board[i - 1][j] == 'O') markBoundary(i - 1 , j , board) ;
        if(i + 1 < board.size() && board[i + 1][j] == 'O') markBoundary(i + 1 , j , board) ;
        if(j - 1 >= 0 && board[i][j - 1] == 'O') markBoundary(i , j - 1 , board) ;
        if(j + 1 < board[0].size() && board[i][j + 1] == 'O') markBoundary(i , j + 1 , board) ;
    }
    
    void replaceOs(int i , int j , vector<vector<char>> & board){
        if(i <= 0 || j <= 0 || i >= board.size() - 1 || j >= board[0].size() - 1) return ;
        board[i][j] = 'X' ;
        if(board[i - 1][j] == 'O') replaceOs(i - 1 , j ,board) ;
        if(board[i + 1][j] == 'O') replaceOs(i + 1 , j ,board) ;
        if(board[i][j - 1] == 'O') replaceOs(i , j - 1 ,board) ;
        if(board[i][j + 1] == 'O') replaceOs(i , j + 1 ,board) ;
    }
};