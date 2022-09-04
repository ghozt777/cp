// link: https://leetcode.com/problems/unique-paths/submissions/

class Solution {
    int mod=2*1e9;
    int res,Tx,Ty;
    void dfs(int x,int y){
        if(x==Tx&&y==Ty){
            res=res%mod+1;
            return;
        }
        if(x>Tx||y>Ty) return;
        dfs(x+1,y);
        dfs(x,y+1);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int j=0;j<n;j++) dp[0][j]=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=dp[i-1][j]+(j-1>=0?dp[i][j-1]:0);
            }
        }
        return dp[m-1][n-1]%mod;
    }
};