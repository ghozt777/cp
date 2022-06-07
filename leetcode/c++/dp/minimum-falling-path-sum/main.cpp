// link : https://leetcode.com/problems/minimum-falling-path-sum/submissions/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size() ;
        const int w = matrix[0].size() ;
        
        vector<vector<int>> dp(n + 1 , vector<int>(w + 1 , INT_MAX)) ;
        for(int i = 0 ; i < w ; i++) dp[1][i + 1] = matrix[0][i] ;
        
        for(int i = 2 ; i <= n ; i++){
            for(int j = 1 ; j <= w ; j++){
                int m = INT_MAX ;
                if(i - 1 >= 1) m = min(m , dp[i - 1][j]) ;
                if(i - 1 >= 1 && j - 1 >= 1) m = min(m , dp[i - 1][j - 1]) ;
                if(i - 1 >= 1 && j + 1 <= w) m = min(m , dp[i - 1][j + 1]) ;
                dp[i][j] = m + matrix[i - 1][j - 1] ;
            }
        }
        
        int res = INT_MAX ;
        for(int i = 1 ; i <= w ; i++){
            res = min(res , dp[n][i]) ;
        }
        
        return res ;
    }
};