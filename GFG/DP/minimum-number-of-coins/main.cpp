// link : https://practice.geeksforgeeks.org/problems/coin-change-minimum-number-of-coins/0 

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long dp[1001]; 
    long long helper(int * coins , int n , int x){
        if(x < 0) return INT_MAX ;
        if(x == 0) return 0 ;
        if(dp[x] != -1) return dp[x] ;
        long long best = INT_MAX ;
        for(int i = 0 ; i < n ; i++) best = min(best , helper(coins , n , x - coins[i]));
        return dp[x] = best != INT_MAX ? best + 1 : INT_MAX;
    }
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        // your code here
        memset(dp , -1 , sizeof(dp)) ;
        long long res =  helper(coins , numberOfCoins , value) ;
        return res == INT_MAX ? -1. : res ;
    }
};