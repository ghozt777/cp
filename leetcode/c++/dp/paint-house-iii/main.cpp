// link: https://leetcode.com/problems/paint-house-iii/

class Solution {
    int t;
    const int INF=INT_MAX;
    long long dp[101][101][22];
    long long solve(vector<int>&houses,vector<vector<int>>&cost,int i,int target,int last){
        if(target>t) return INF;
        if(i==houses.size()) return target==t?0:INF;
        if(dp[i][target][last]!=-1) return dp[i][target][last];
        long long res=INF;
        if(houses[i]!=0) res=solve(houses,cost,i+1,target+(houses[i]!=last),houses[i]);
        else{
            for(int j=0;j<cost[i].size();j++){
                res=min(res,solve(houses,cost,i+1,target+(last!=j+1),j+1)+(long long)cost[i][j]);
            }
        }
        return dp[i][target][last]=res;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        t=target;
        memset(dp,-1,sizeof(dp));
        long long res=solve(houses,cost,0,0,21);
        return res==INF?-1:res;
    }
};