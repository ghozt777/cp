// link : https://leetcode.com/problems/delete-operation-for-two-strings/submissions/

class Solution {
    // bruteforce
    int bf(string & s1 , string &s2 , int n1 , int n2){
        if(n1 == 0 || n2 == 0) return 0 ;
        if(s1[n1 - 1] == s2[n2 - 1]) return 1 + bf(s1 , s2 , n1 - 1 , n2 - 1) ;
        else return max({ bf(s1 , s2 , n1 , n2 - 1) , bf(s1 , s2 , n1 - 1 , n2) }) ;
    }
    
    // dp
    int longestCommonSubsequence(string &s1 , string &s2){
        const int n = s1.length() ;
        const int m = s2.length() ;
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0)) ;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1] ;
                else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
            }
        }
        return dp[n][m] ;
    }
    
public:
    int minDistance(string word1, string word2) {
        // int m = bf(word1 , word2 , word1.length() , word2.length()) ;
        int longest_substring_length = longestCommonSubsequence(word1 , word2) ;
        return word1.length() + word2.length() - 2 * longest_substring_length ;
    }
};