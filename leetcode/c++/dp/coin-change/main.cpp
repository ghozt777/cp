// link : https://leetcode.com/problems/coin-change/


class Solution {
    const int INF = INT_MAX - 1;
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1 , INF) ;
        dp[0] = 0 ;
        for(int i = 1 ; i <= amount ; i++){
            for(int x : coins){
                if(x <= i) dp[i] = min(dp[i] , 1 + dp[i - x]) ;
            }
        }
        return dp[amount] == INF ? -1 : dp[amount] ;
    }
};