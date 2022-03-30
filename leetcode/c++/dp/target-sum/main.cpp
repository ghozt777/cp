// link : https://leetcode.com/problems/target-sum/

class Solution {
int solve(vector<int>& arr, int sum){
    const int n = arr.size();
    int dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = 1; // if sum = 0 total number of subsets = 1 
    for(int i = 1; i <= sum; i++) dp[0][i] = 0; // if n = 0 then except for sum = 0 , for any value of sum count = 0 
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(arr[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target) ;
        int sum = 0 ;
        for(int x : nums) sum += x ;
        if(sum < target || (target + sum) % 2 != 0) return 0 ;
        int s1 = (sum + target) / 2 ;
        return solve(nums , s1) ;
    }
};