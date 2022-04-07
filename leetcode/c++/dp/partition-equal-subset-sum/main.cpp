// link : https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
    bool subset_sum(vector<int> & arr , int sum){
        const int n = arr.size() ;
        bool dp[n + 1][sum + 1] ;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 1 ;
        for(int i = 1 ; i <= sum ; i++) dp[0][i] = 0 ;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= sum ; j++){
                if(arr[i - 1] <= j) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]] ;
                else dp[i][j] = dp[i - 1][j] ; 
            }
        }
        return dp[n][sum] ;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int x : nums) sum += x ;
        if(sum % 2) return false ;
        return subset_sum(nums , sum / 2) ;
    }
};