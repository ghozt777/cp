// link : https://leetcode.com/problems/where-will-the-ball-fall/submissions/

class Solution {
    vector<vector<int>> dp ;
    int dfs(int i , int j , vector<vector<int>> & grid){
        if(i == grid.size()) return j ;
        if(dp[i][j] != INT_MAX) return dp[i][j] ;
        if(grid[i][j] == 1){
            if((j == grid[0].size() - 1) || grid[i][j + 1] == -1) return -1 ;
            else return dp[i][j] = dfs(i + 1 , j + 1 , grid) ;
        }
        else{
            if((j == 0) || grid[i][j - 1] == 1) return -1 ;
            else return dp[i][j] = dfs(i + 1 , j - 1 , grid) ;
        }
        return dp[i][j] = -1 ;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        dp.resize(grid.size() , vector<int>(grid[0].size() , INT_MAX))  ;
        vector<int> res(grid[0].size()) ;
        for(int i = 0 ; i < grid[0].size() ; i++) res[i] = dfs(0 , i , grid) ;
        return res ;
    }
};