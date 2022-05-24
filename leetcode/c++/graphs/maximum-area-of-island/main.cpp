// link : https://leetcode.com/problems/max-area-of-island/submissions/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int n = grid.size() ;
        const int m = grid[0].size() ;
        int res = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) res = max(res , getArea(i , j , grid)) ;
            }
        }
        return res ;
    }
    int getArea(int i , int j , vector<vector<int>> & grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 0 ;
        grid[i][j] = 0 ;
        return 1 + getArea(i - 1 , j , grid) + getArea(i + 1 , j , grid) + getArea(i , j - 1 , grid) + getArea(i , j + 1 , grid) ;
    }
};