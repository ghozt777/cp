// link : https://leetcode.com/problems/longest-palindromic-substring/submissions/

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length() ;
        vector<vector<bool>> dp(n , vector<bool>(n,false)) ;
        
        // for first and second diagonal
        for(int i=0;i<n;i++){
            dp[i][i]=true ;
            if(i+1<n) dp[i][i+1]=s[i]==s[i+1] ;
        }
        
        // for third diagonal onwards
        // diagonal wise traversal not row-wise or column-wise
        for(int len=2;len<n;len++){
            for(int i=0;i<n;i++){
                int j=i+len ;
                if(j<n) dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
            }
        }
        
        int maxLen=INT_MIN ;
        int start=0,end=0 ;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] && (j-i+1)>maxLen){
                    maxLen=j-i+1 ;
                    start=i;
                    end=j ;
                }
            }
        }
        
        return s.substr(start,end-start+1) ;
    }
};