// link: https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
const int MOD=1e9+7;
int dp[51][51][51];
public:
    Solution(){memset(dp,-1,sizeof(dp));}
    int findPaths(int m, int n, int max, int x, int y) {
        if(x<0||y<0||x>=m||y>=n) return 1;
        if(max<=0) return 0;
        if(dp[x][y][max]!=-1)return dp[x][y][max];
        long long res=0;
            res+=findPaths(m,n,max-1,x+1,y);
            res+=findPaths(m,n,max-1,x,y+1);
            res+=findPaths(m,n,max-1,x-1,y);
            res+=findPaths(m,n,max-1,x,y-1);
        return dp[x][y][max]=res%MOD;
    }
};