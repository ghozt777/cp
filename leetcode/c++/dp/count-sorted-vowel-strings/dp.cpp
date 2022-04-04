// link : https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n + 1][5] ;
        for(int i = 0 ; i < 5 ; i++) dp[1][i] = 1 ;
        for(int i = 2 ; i <= n ; i++){
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] ;
            dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
            dp[i][2] = dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
            dp[i][3] = dp[i - 1][3] + dp[i - 1][4];
            dp[i][4] = dp[i - 1][4];
        }
        int sum = 0 ;
        for(int i = 0 ; i < 5 ; i++) sum += dp[n][i] ;
        return sum ;
    }
};