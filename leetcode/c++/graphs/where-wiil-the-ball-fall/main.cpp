// link : https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
    int dfs(int i , int j , vector<vector<int>> & grid){
        if(i == grid.size()) return j ;
        if(grid[i][j] == 1){
            if((j == grid[0].size() - 1) || grid[i][j + 1] == -1) return -1 ;
            else return dfs(i + 1 , j + 1 , grid) ;
        }
        else{
            if((j == 0) || grid[i][j - 1] == 1) return -1 ;
            else return dfs(i + 1 , j - 1 , grid) ;
        }
        return -1 ;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size()) ;
        for(int i = 0 ; i < grid[0].size() ; i++) res[i] = dfs(0 , i , grid) ;
        return res ;
    }
};