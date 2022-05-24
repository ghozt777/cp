// link : https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size() ;
        const int m = grid[0].size() ;
        int noOfIslands = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    ++noOfIslands ;
                    removeIslands(i , j , grid) ;
                }
            }
        }
        return noOfIslands ;
    }
    
    void removeIslands(int i , int j , vector<vector<char>> & grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return ;
        grid[i][j] = '0' ;
        removeIslands(i - 1 , j , grid) ;
        removeIslands(i + 1 , j , grid) ;
        removeIslands(i , j + 1 , grid) ;
        removeIslands(i , j - 1 , grid) ;
    }
};