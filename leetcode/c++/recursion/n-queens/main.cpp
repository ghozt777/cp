// link : https://leetcode.com/problems/n-queens/
// Algo Used: Backtracking

class Solution {
public:
    bool ok(int x , int y , vector<string> & grid){
        int i = x ;
        int j = y ;
        while(i >= 0 && j < grid.size()){
            if(grid[i][j] == 'Q') return false ;
            --i ;
            ++j ;
        }

        i = x ;
        j = y ;
        while(i >= 0 && j >= 0){
            if(grid[i][j] == 'Q') return false ;
            --i ;
            --j ;
        }

        i = x ;
        j = y ;
        while(i >= 0){
            if(grid[i][j] == 'Q') return false ;
            --i ;
        }

        return true ;
    }

    void nQueen(vector<string> & curr , int i , vector<vector<string>> & res){
        if(i >= curr.size()){
            res.push_back(curr) ;
            return ;
        }
        const int n = curr.size() ;
        for(int j = 0 ; j < n ; j++){
            if(ok(i , j, curr)){
            curr[i][j] = 'Q' ;
            nQueen(curr , i + 1 , res) ;
            curr[i][j] = '.' ;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string str = "" ;
        for(int i = 0 ;i < n ; i++) str += '.' ;
        vector<string> grid(n , str)   ;
        vector<vector<string>> res ;
        
        nQueen(grid , 0 ,res) ;
        return res ;
    }
};