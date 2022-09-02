// link: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint32_t > dp(1001,0);
        for(int x:nums) dp[x]=1;
        for(int n=1;n<=target;n++){
            for(int i=0;i<nums.size();i++){
                if(n-nums[i]>0) dp[n]+=dp[n-nums[i]];
            }
        }
        return dp[target];
    }
};