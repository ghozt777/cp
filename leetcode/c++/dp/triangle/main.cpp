// link : https://leetcode.com/problems/triangle/

class Solution {
    int dfs(vector<vector<int>>& triangle , int r , int c){
        if(r == triangle.size()) return 0 ;
        int res = triangle[r][c] ;
        res += min({ dfs(triangle , r + 1 ,c) , dfs(triangle , r + 1 , c + 1) }) ;
        return res ;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // return dfs(triangle , 0 , 0) ;
        const int n = triangle.size() ;
        vector<vector<int>> dp(n , vector<int>(n , 0)) ;
        dp[0][0] = triangle[0][0] ;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < triangle[i].size() ; j++){
                if(j == 0) dp[i][j] = triangle[i][j] + dp[i - 1][j] ;
                else if(j == triangle[i].size() - 1) dp[i][j] = triangle[i][j] + dp[i - 1][j - 1] ;
                else dp[i][j] = triangle[i][j] + min(dp[i - 1][j] , dp[i - 1][j - 1]) ;
            }
        }
        int res = INT_MAX ;
        for(int x : dp[n - 1]) res = min(res , x) ;
        return res ;
    }
};